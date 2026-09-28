#include <iostream>
#include <render/render.h>

int main() {
    system("cls");
    printf("[-------------]ImGui-Overlay-------------]\n");
    printf("[-----PRESS RIGHT SHIFT TO OPEN MENU-----]\n");

    if (!render->create_window()) {
        printf("Failed to create window");    
        return 1;
    }
    
    if (!render->create_device()) {
        printf("Failed to create device");

        return 1;
    }

    if (!render->create_imgui()) {
        printf("Failed to create imgui");
        return 1;
    }

    while (true) {
        render->start_render();
        render->render_visuals();

        if (render->running) {
            render->render_menu();
        }

        render->end_render();

    }

    return 0;
}