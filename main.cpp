//#include <iostream>
//#include <vector>
//#include <ctime>
//#include <queue>
//#include <algorithm>
//
//#include "Cases.h"
//#include "Accused.h"
//#include "Judge.h"
//#include "Lawyer.h"
//#include "Judgement.h"
//
//class cmp
//{
//public:
//	bool operator()(const Cases& a, const Cases& b)
//	{
//		if (a.m_case_priority == b.m_case_priority) {
//			if (a.m_case_type == b.m_case_type) {
//				if (a.m_case_heard == b.m_case_heard) {
//					return a.m_time_req > b.m_time_req;
//				}
//				return a.m_case_heard < b.m_case_heard;
//			}
//			return a.m_case_type > b.m_case_type;
//		}
//		return a.m_case_priority > b.m_case_priority;
//	}
//};
//
//int main(int argc, char* argv[])
//{
//	std::cout << "working\n";
//	int n;
//    std::cout << "Enter how many cases you want to enter : ";
//    std::cin >> n;
//    std::cout << "Enter " << n << " Cases :- \n";
//	std::cin.ignore();
//	std::vector<Cases> arr(n);
//	std::cout << "Enter " << n << " times for simulation : ";
//	std::vector<Cases> vec;
//	std::priority_queue<Cases, std::vector<Cases>, cmp> pq;
//	for (int i = 0; i < n; i++) {
//		arr[i].display();
//		pq.push(arr[i]);
//	}
//	int day = 1;
//	int complete = 0;
//	int remaning = 21600;
//	while (!pq.empty()) {
//		arr.clear();
//		while (remaning > 0 && !pq.empty()) {
//			Cases temp = pq.top();
//			pq.pop();
//			if (remaning >= 3600 && (temp.m_time_req - 3600) >= 0) {
//				temp.m_time_req -= 3600;
//				remaning -= 3600;
//			}
//			else if (remaning-temp.m_time_req >= 0) {
//				remaning -= temp.m_time_req;
//				temp.m_time_req = 0;
//			}
//			else {
//				temp.m_time_req -= remaning;
//				remaning = 0;
//			}
//			temp.m_case_heard++;
//			temp.setTime(time(0)+((long long)day*86400 + 21600 - remaning));
//			arr.push_back(temp);
//		}
//		if (remaning <= 0) {
//			day++;
//			remaning += 216000;
//		}
//		
//		while (!pq.empty()) {
//			Cases temp = pq.top();
//			if (temp.m_case_priority > 0)
//				temp.m_case_priority--;
//			arr.push_back(temp);
//		}
//		for (Cases& e : arr) {
//			if (e.m_time_req <= 0) {
//				complete++;
//				e.m_case_status = 0;
//				vec.push_back(e);
//			}
//			else {
//				pq.push(e);
//			}
//				
//		}
//	}
//	for (const Cases& e : vec) {
//		e.display();
//	}
//
//	return 0;
//}
//
//
//
//
//
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

void Dashboard()
{
    static char f_name[32] = "";
    static char l_name[32] = "";
    static char father_name[32] = "";
    static char mother_name[32] = "";
    static char address[64] = "";
    static char dob[16] = "";
    static char sex[] = "";
    static char msg[64] = "";
    static int age;

    float width = ImGui::GetWindowWidth();
    float height = ImGui::GetWindowHeight();

    ImGui::BeginChild("Form", ImVec2(width - 150.0f, height - 200.0f), false);
    static float x = (ImGui::GetCursorPosX() + ImGui::GetColumnWidth() - ImGui::CalcTextSize("Enter Case Details").x - ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x) / 2, y = 25.0f;
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4.0f, y));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 0.8f));
    ImGui::SetCursorPos(ImVec2(x, y));
    ImGui::Text("Enter Case Details");
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();

    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10.0f, 5.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4.0f, 6.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 0.0f, 1.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.3f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.7f));

    ImGui::InputText("Case", f_name, 20, ImGuiInputTextFlags_CharsNoBlank);
    ImGui::InputText("Judge Name", l_name, 20);
    ImGui::InputText("Petitioner Name", father_name, 20);
    ImGui::InputText("Accused Name", mother_name, 20);
    ImGui::InputInt("Priority", &age, false);
    ImGui::InputText("Starting Date", dob, 16, ImGuiInputTextFlags_CharsDecimal);
    ImGui::InputText("Lawyer Names", address, 64);
    static int selectfamily = 0;
    /*if (ImGui::BeginCombo("Select Family", family.size() == 0 ? "Create Family" : family[selectfamily].f_name))
    {
        for (int c = 0, size = (int)family.size(); c < size; c++)
        {
            const bool is_selected = (selectfamily == c);
            if (ImGui::Selectable(family[c].f_name, is_selected))
                selectfamily = c;
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }*/
    const char* s[] = { "Male", "Female" };
    static int sel = 0;
    ImGui::RadioButton(s[0], &sel, 0); ImGui::SameLine();
    ImGui::RadioButton(s[1], &sel, 1); ImGui::SameLine();
    sel == 0 ? sex[0] = 'M' : sex[0] = 'F';
    ImGui::NewLine();

    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.3f));
    if (ImGui::Button("Submit", ImVec2(250.0f, 40.0f)))
    {
        /*bool status = false;
        if (f_name[0] == NULL || l_name[0] == NULL || father_name[0] == NULL || mother_name[0] == NULL || dob[0] == NULL || address[0] == NULL || age == 0)
        {
            strcpy_s(msg, "Field cannot be blank.");
        }
        else
        {
            status = insertPeople(f_name, l_name, father_name, mother_name, age, dob, sex[0], address, selectfamily);
            if (status)
            {
                strcpy_s(f_name, "");
                strcpy_s(l_name, "");
                strcpy_s(father_name, "");
                strcpy_s(mother_name, "");
                strcpy_s(dob, "");
                strcpy_s(sex, "");
                strcpy_s(address, "");
                age = 0;
                selectfamily = 0;
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
                strcpy_s(msg, "Last Record saved successfully ...");
                ImGui::PopStyleColor(1);
            }
            else
            {
                strcpy_s(msg, "Sorry : Some error happen in saving record.");
            }
        }*/
    }
    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
    {
        strcpy_s(msg, "");
    }
    ImGui::Text("%s", msg);
    ImGui::PopStyleVar(3);
    ImGui::PopStyleColor(6);
    ImGui::EndChild();

    float childBgColor = 25.0f / 255.0f;
    ImGui::SetCursorPos(ImVec2((width / 2 - 300), (height - 190)));
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 8.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);

    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(childBgColor, childBgColor, childBgColor, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
    ImGui::BeginChild("Preview", ImVec2(600.0f, 180.0f), true);
    ImGui::Text("Case : %s\nJudge Name : %s\nPetitioner's Name : %s \nAccused Name : %s\nPriority : %d\nSex : %c\nStarting Date: %s\nLawyers Name : %s", f_name, l_name, father_name, mother_name, age, sex[0], dob, address);
    ImGui::EndChild();
    ImGui::PopStyleColor(2);
    ImGui::PopStyleVar(2);
}


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

    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
 
#endif
    GLFWwindow* window = glfwCreateWindow(1280, 680, "Case Record", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);



    glfwSwapInterval(1);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows


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

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    io.Fonts->AddFontFromFileTTF("external/imgui/misc/fonts/Roboto-Medium.ttf", 19.0f);

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
    Menu menu[] = { {"Home", true}, {"Case Detail ", false}, {"Judge Name", false}, {"Accused", false}, {"Petitioner", false}, {"Lawyer", false} };

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

        ImGui::SetNextWindowSize(ImVec2(viewport->Size.x - 250.0f, viewport->Size.y));
        ImGui::SetNextWindowPos(ImVec2(viewport->Pos.x + 250.0f, viewport->Pos.y));
        if (menu[0].btnActive)
        {
            ImGui::Begin(menu[0].btnName.c_str(), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
            Dashboard();
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