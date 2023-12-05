#if 0
#include <ceres/ceres.h>
#include <ceres/rotation.h>
#include <iostream>

struct CostFunctor {
  template <typename T> bool operator()(const T *const x, T *residual) const {
    // The linear model: y = 5x + 3
    residual[0] = T(5.0) * x[0] + T(3.0);
    return true;
  }
};

int main() {
  // Initial guess for the parameter (slope) value.
  double initial_slope = 1.0;

  // Create the problem.
  ceres::Problem problem;

  // Add a single residual block to the problem.
  ceres::CostFunction *cost_function = new ceres::AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor);
  problem.AddResidualBlock(cost_function, nullptr, &initial_slope);

  // Set solver options (if needed).
  ceres::Solver::Options options;
  options.minimizer_progress_to_stdout = true;

  // Solve the problem.
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  // Print the results.
  std::cout << summary.FullReport() << std::endl;
  std::cout << "Slope (fitted): " << initial_slope << std::endl;

  return 0;
}

#endif

#if 0
#include <ceres/ceres.h>
#include <vector>

// 代价函数的计算模型
struct CostFunctor {
  CostFunctor(const double x, const double y) : x_(x), y_(y) {}
  template <typename T> bool operator()(const T *const m, const T *const c, T *residual) const {
    residual[0] = T(y_) - (m[0] * T(x_) + c[0]);
    return true;
  }

private:
  const double x_;
  const double y_;
};

int main() {
  double m = 0.0; // 初始估计值
  double c = 0.0; // 初始估计值

  // 创建求解器
  ceres::Problem problem;

  // 用于存储观测数据的向量
  const std::vector<double> x_data = {1, 2, 3, 4, 5};
  const std::vector<double> y_data = {8, 13, 18, 23, 28};

  for (int i = 0; i < x_data.size(); ++i) {
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<CostFunctor, 1, 1, 1>(new CostFunctor(x_data[i], y_data[i])), nullptr, &m, &c);
  }

  // 配置求解器并求解问题
  ceres::Solver::Options options;
  // options.linear_solver_type = ceres::DENSE_QR;
  options.minimizer_progress_to_stdout = true;
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  std::cout << "Final slope (m): " << m << std::endl;
  std::cout << "Final intercept (c): " << c << std::endl;

  return 0;
}
#endif

#include <ceres/ceres.h>
#include <iostream>

struct CostFunctor {
  CostFunctor(double x, double y) : x_(x), y_(y) {}

  template <typename T> bool operator()(const T *const a, const T *const b, T *residual) const {
    residual[0] = T(y_) - *a * ceres::pow((T(x_) - *b), 2);
    return true;
  }

private:
  const double x_;
  const double y_;
};

int main() {
  // Generate some synthetic data.
  std::vector<float> x_data;
  std::vector<float> y_data;

  // y=1/2*(x-10)^2
  for (int i = 0; i < 100; i++) {
    x_data.push_back(i);
    y_data.push_back(1 / 2.0F * std::pow((x_data[i] - 10), 2));
  }

  // Initial guesses for parameters a, b, c.
  double initial_a = 0.0;
  double initial_b = 0.0;

  // Create the problem.
  ceres::Problem problem;
  for (int i = 0; i < 100; ++i) {
    ceres::CostFunction *cost_function =
        new ceres::AutoDiffCostFunction<CostFunctor, 1, 1, 1>(new CostFunctor(x_data[i], y_data[i]));
    problem.AddResidualBlock(cost_function, nullptr, &initial_a, &initial_b);
  }

  // Set solver options (if needed).
  ceres::Solver::Options options;
  // options.max_num_iterations = 200000;
  // options.max_linear_solver_iterations = 1000000;
  // options.min_linear_solver_iterations = 100000;
  options.minimizer_progress_to_stdout = true;

  // Solve the problem.
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  // Print the results.
  std::cout << summary.FullReport() << std::endl;
  std::cout << "Parameter a (fitted): " << initial_a << std::endl;
  std::cout << "Parameter b (fitted): " << initial_b << std::endl;
  // std::cout << "Parameter c (fitted): " << initial_c << std::endl;

  return 0;
}
