#include <GL/gl.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
struct Line{
    int x1,x2,y1,y2;
};
struct Color{
    int R[150];
    int G[94];
    int B[252];
};


int main(int argc, char* argv[]){
    struct Line line1;
    struct Color color1;

  int error_code;
  SDL_Window* window;
  bool need_run;
  SDL_Event event;
  SDL_GLContext gl_context;
  int i;
  SDL_Renderer* renderer;

    int Max_lineCount = 10;
    int x1[Max_lineCount];
    int x2[Max_lineCount];
    int y1[Max_lineCount];
    int y2[Max_lineCount];
    int esemeny = 0;

  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  window = SDL_CreateWindow(
    "Hello SDL!",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    1280, 720,
    SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,150,94,252, 255);
    for(i; i<Max_lineCount;i++){
    SDL_RenderDrawLine(renderer,x1[i], y1[i], x2[i], y2[i]);
    }
    SDL_RenderPresent(renderer);
    i=0;
  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
          case SDL_KEYDOWN:
            case SDL_SCANCODE_Q:
            need_run = false;
            break;
          case SDL_QUIT:
            need_run = false;
            break;
          case SDL_MOUSEBUTTONDOWN:
                if(i != Max_lineCount){
                    if(esemeny ==0 ){
                        SDL_GetMouseState(&line1.x1, &line1.y1);
                        SDL_Log("%d-ik a pont: %d, %d",i, line1.x1, line1.y1);
                        x1[i]=line1.x1;
                        y1[i]=line1.y1;
                        esemeny++;
                    }
                    else if(esemeny == 1){
                        SDL_GetMouseState(&line1.x2, &line1.y2);
                        SDL_Log("b pont: %d, %d", line1.x2, line1.y2);
                        x2[i]=line1.x2;
                        y2[i]=line1.y2;
                        esemeny=0;
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                        SDL_SetRenderDrawColor(renderer,150,94,252, 255);
                        SDL_RenderDrawLine(renderer,x1[i], y1[i], x2[i], y2[i]);
                        SDL_RenderPresent(renderer);
                        i++;
                    }
                }
                break;
            }
        }
    }


  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();
      return 0;
}

