#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

// clang-format off
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
// clang-format on

#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <iostream>

using namespace gl;

GLFWwindow *window;

// 用于绘制的直线的起点和终点
ImVec2 lineStart = ImVec2(100.0f, 100.0f);
ImVec2 lineEnd = ImVec2(300.0f, 300.0f);

void Render() {
  glClear(GL_COLOR_BUFFER_BIT);

  // 在这里添加你的OpenGL渲染代码

  // ImGui渲染
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  // 在这里添加ImGui界面代码
  ImGui::Begin("ImGui Line Example");

  // 绘制一条红色直线，大小为10 pixel
  ImGui::GetWindowDrawList()->AddLine(lineStart, lineEnd, ImColor(255, 0, 0, 255), 1.0f);
  ImGui::GetWindowDrawList()->AddRect(lineStart, lineEnd, ImColor(0, 255, 0, 255), 1.0f);

  const ImVec2 points[]{{100, 100}, {100, 200}, {200, 200}, {300, 300}, {200, 300}, {100, 100}};
  ImGui::GetWindowDrawList()->AddPolyline(points, sizeof(points), ImColor(0, 0, 255, 255 / 2),
                                          ImDrawFlags_RoundCornersAll, 1.F);
  // const auto &[x, y] = ImGui::GetCursorScreenPos();
  // std::cout << "x:" << x << ", y:" << y << std::endl;
  // const auto &[px, py] = ImGui::GetCursorStartPos();
  // std::cout << "px:" << px << ", py:" << py << std::endl;

  ImGui::End();

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  // 交换缓冲区
  glfwSwapBuffers(window);
}

int main() {
  // glbinding::initialize(glfwGetProcAddress);
  // 初始化GLFW
  if (!glfwInit()) {
    // 处理初始化失败的情况
    return -1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, static_cast<int>(GL_TRUE));
#endif

  std::cout << "glfwVulkanSupported: " << glfwVulkanSupported() << std::endl;

  // 创建窗口
  window = glfwCreateWindow(800, 600, "ImGui Line Example", nullptr, nullptr);
  if (!window) {
    // 处理窗口创建失败的情况
    glfwTerminate();
    return -1;
  }

  // 创建OpenGL上下文
  glfwMakeContextCurrent(window);
  // glfwSwapInterval(1);
  glbinding::initialize(glfwGetProcAddress);

  // 设置OpenGL状态等
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

  // 初始化ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  // 主循环
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // 在这里添加更新逻辑

    Render();
  }

  // 清理资源
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
