// Window.cpp

#include "Engine/Engine.h"

#include "Render/Window.h"
#include "Render/Shader.h"
#include "Render/Model.h"
#include "Render/Render.h"
#include "Render/Texture.h"

struct Window {
  bool initialized;
  struct SDL_Window* window;
  SDL_GLContext context;
  SDL_Event event;
};

static struct Window _window;

struct Model _model;
struct Shader _shader;
struct Texture _texture;

int windowCreate(const char* title, int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("%s\n", SDL_GetError());
    return -1;
  }

  _window = (struct Window) {
    .initialized = true
  };

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  _window.window = SDL_CreateWindow(title,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width, height,
    SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
  );

  if (!_window.window) {
    printf("%s\n", SDL_GetError());
    return -1;
  }

  _window.context = SDL_GL_CreateContext(_window.window);

  if (!_window.context) {
    printf("%s\n", SDL_GetError());
    return -1;
  }

#ifdef __APPLE__
  glewExperimental = GL_TRUE;
#endif

  int err = glewInit();

  if (GLEW_OK != err) {
    printf("Error: %s\n", glewGetErrorString(err));
    return -1;
  }

  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glShadeModel(GL_FLAT);

  glFrontFace(GL_CW);
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);

  printf("GL VENDOR:    %s\n", glGetString(GL_VENDOR));
  printf("GL RENDERER:  %s\n", glGetString(GL_RENDERER));
  printf("GL VERSION:   %s\n", glGetString(GL_VERSION));
  printf("GLSL VERSION: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
  printf("--\n");

  _texture = loadTexture("Resources/Textures/Texture_Stall");
  _model = createModel("Resources/Meshes/Stall");
  _shader = createShader("Resources/Shaders/Core");
  // glGetUniformLocation(_shader.program, "tex");
  return 0;
}

int windowEvent() {
  while (SDL_PollEvent(&_window.event)) {
    switch (_window.event.type) {
      case SDL_QUIT: {
        return -1;
      }
        break;

      case SDL_KEYDOWN: {
        switch (_window.event.key.keysym.sym) {
          case SDLK_ESCAPE: {
            return -1;
          }
          break;

        default:
          break;
        }
      }
        break;

      default:
        break;
    }
  }
  return 0;
}

void windowClear() {
  glClearColor(0.25f, 0.22f, 0.37f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void windowRender() {
  SDL_Window* window = _window.window;
  if (!window) return;

  useShader(&_shader);
  renderTexturedModel(&_model, &_texture);

  SDL_GL_SwapWindow(window);
}

void windowDestroy() {
  freeTexture(&_texture);
  freeShader(&_shader);
  freeModel(&_model);

  SDL_DestroyWindow(_window.window);
  SDL_GL_DeleteContext(_window.context);
  SDL_Quit();
}
