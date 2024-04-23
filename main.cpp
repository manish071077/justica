//





#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"




#define STB_IMAGE_IMPLEMENTATION
#include "stb.h"
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif
#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}
int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif
    GLFWwindow* window = glfwCreateWindow(1280, 680, "Citizen's Record", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);

    /*int width, height, channels;
    unsigned char* pixels = stbi_load("external/imgui/misc/picture/citizen.png", &width, &height, &channels, 4);
    GLFWimage images[1];
    images[0].height = height;
    images[0].width = width;
    images[0].pixels = pixels;
    glfwSetWindowIcon(window, 1, images);*/

    glfwSwapInterval(1);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();
    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.



    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
        style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.068f, 0.939f, 0.141f, 1.0f);
        style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.068f, 0.939f, 0.141f, 0.196f);
        style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.098f, 0.098f, 0.098f, 1.0f);
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.515f, 0.991f, 0.384f, 1.0f);
        style.Colors[ImGuiCol_Header] = ImVec4(0.068f, 0.939f, 0.141f, 1.0f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.515f, 0.991f, 0.384f, 0.5f);
        style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.515f, 0.991f, 0.384f, 0.0f);
        style.Colors[ImGuiCol_CheckMark] = ImVec4(0.068f, 0.939f, 0.141f, 1.0f);

        style.WindowBorderSize = 0.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    io.Fonts->AddFontFromFileTTF("external/imgui/misc/fonts/Roboto-Medium.ttf", 19.0f);
    /*city.font1 = io.Fonts->AddFontFromFileTTF("external/imgui/misc/fonts/Roboto-Medium.ttf", 40.0f);
    city.fontpreview = io.Fonts->AddFontFromFileTTF("external/imgui/misc/fonts/Roboto-Medium.ttf", 23.0f);*/
    //io.Fonts->AddFontFromFileTTF("external/imgui/misc/fonts/Cousine-Regular.ttf", 17.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    struct Menu
    {
        std::string btnName;
        bool btnActive;
        Menu(std::string name, bool active)
        {
            btnName = name;
            btnActive = active;
        }
    };

    ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    Menu menu[] = { {"Home", true}, {"Add a people", false}, {"People", false}, {"Family", false}, {"Village", false}, {"City", false} };

    //ImU32 color = ImColor(1.0f, 1.0f, 1.0f, 0.0f);

#ifdef __EMSCRIPTEN__

    io.IniFilename = NULL;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!glfwWindowShouldClose(window))
#endif
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        float bgDarkColor = 25.0f / 255.0f;
        //default side bar
        ImGui::SetNextWindowSize(ImVec2(250.0f, viewport->Size.y));
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(bgDarkColor, bgDarkColor, bgDarkColor, 1.0f));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::Begin("sidebar", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
        for (int i = 0; i < 6; i++)
        {
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.7f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.3f));

            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 3.0f);

            if (ImGui::Button(menu[i].btnName.c_str(), ImVec2(250.0f, 45.0f)))
            {
                for (int j = 0; j < 6; j++)
                {
                    i == j ? menu[j].btnActive = true : menu[j].btnActive = false;
                }
            }
            ImGui::PopStyleVar();
            ImGui::PopStyleColor(3);
        }
        float ypos = ImGui::GetCursorPosY();
        ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 40.0f);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.068f, 0.939f, 0.141f, 1.0f));
        ImGui::Text("Framerate : %.1f FPS", ImGui::GetIO().Framerate);
        ImGui::PopStyleColor();
        ImGui::SetCursorPosY(ypos);
        ImGui::End();
        ImGui::PopStyleVar();
        ImGui::PopStyleColor();

        //It is the main workspace of the application.
        ImGui::SetNextWindowSize(ImVec2(viewport->Size.x - 250.0f, viewport->Size.y));
        ImGui::SetNextWindowPos(ImVec2(viewport->Pos.x + 250.0f, viewport->Pos.y));
        if (menu[0].btnActive)
        {
            ImGui::Begin(menu[0].btnName.c_str(), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
            //Dashboard();
            ImGui::End();
        }
        if (menu[1].btnActive)
        {
            ImGui::Begin(menu[1].btnName.c_str(), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
           // city.guiInsert();
            ImGui::End();
        }
        if (menu[2].btnActive)
        {
            ImGui::Begin(menu[2].btnName.c_str(), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
            //city.tablePeople();
            ImGui::End();
        }
        if (menu[3].btnActive)
        {
            ImGui::Begin(menu[3].btnName.c_str(), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
            //city.tableFamily();
            ImGui::End();
        }
        if (menu[4].btnActive)
        {
            ImGui::Begin(menu[4].btnName.c_str(), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
            //city.showVillage();
            ImGui::End();
        }
        if (menu[5].btnActive)
        {
            ImGui::Begin(menu[4].btnName.c_str(), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
            //city.showCity();
            ImGui::End();
        }



        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
        //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window);
    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}