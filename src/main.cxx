#include <iostream>
#include <vector>
#include <memory>

namespace rl {
#include <raylib.h>
}


#include "./algorithms.hxx"



#define WIDTH 1920
#define HEIGHT 1080





int main() {


    Bubblesort bubblesort(200);

    float time{0.0f};


    rl::InitWindow(WIDTH, HEIGHT, "Sorting Algorithms");

    while (!rl::WindowShouldClose()) {
        rl::BeginDrawing();
        {
            rl::ClearBackground(rl::BLACK);

            size_t list_size = bubblesort.m_item_count;

            for (size_t i=0; i < list_size; ++i) {

                int rect_width = WIDTH / list_size;

                float value = bubblesort.m_list[i];


                DrawRectangle(
                    i * rect_width,
                    (1 - value) * HEIGHT,
                    rect_width,
                    value * HEIGHT,
                    i == bubblesort.m_cursor ? rl::RED : rl::WHITE
                );


            }



            if (bubblesort.is_done()) {
                bubblesort.reset();
            }

            float ft = rl::GetFrameTime();
            time += ft;

            if (time >= 0.0001f) {
                bubblesort.next();
                time = 0;
            }



        }
        rl::EndDrawing();
    }

    rl::CloseWindow();

    return EXIT_SUCCESS;
}
