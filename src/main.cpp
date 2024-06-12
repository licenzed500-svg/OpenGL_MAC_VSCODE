#include "vendors/GLFW/glfw3.h"

int main() {
// Initialize GLFW
if (!glfwInit()) {
// Handle initialization failure
return -1;
}

// Create a window
GLFWwindow* window = glfwCreateWindow(800, 600, "Hello World", nullptr, nullptr);
if (window == nullptr) {
// Handle window creation failure
glfwTerminate();
return -1;
}

// Make the window context current
glfwMakeContextCurrent(window);

// Main loop
while (!glfwWindowShouldClose(window)) {
// Render your content here

// Swap buffers
glfwSwapBuffers(window);

// Poll for events
glfwPollEvents();
}

// Clean up and exit
glfwTerminate();
return 0;
}