#include <SDL.h>

class Animation{
public:
    Animation(int height_, int width_): height(height_), width(width_){
        SDL_Init(SDL_INIT_VIDEO);       // Initializing SDL as Video
        SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);      // setting draw color
        SDL_RenderClear(renderer);      // Clear the newly created window
        SDL_RenderPresent(renderer);    // Reflects the changes done in the
        //  window.
    }
    // Destructor
    ~Animation(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    Animation(Animation const& Animation) = delete;
    Animation(Animation&& Animation) = default;
    Animation& operator=(const Animation& Animation) = delete;
    Animation& operator=(Animation&& Animation) = default;

    void Draw_Circle(int c_x,int c_y, int radius_) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        for (int i = c_x - radius_; i <= c_x + radius_; ++i) {
            for (int j = c_y - radius_; j <= c_y + radius_; ++j) {
                if ((pow(c_y - j, 2) + pow(c_x - i, 2))
                    <= std::pow(radius_, 2)) {
                    SDL_RenderDrawPoint(renderer, i, j);
                }
            }
            SDL_RenderPresent(renderer);
        }
        SDL_RenderPresent(renderer);
    }

    [[nodiscard]] int get_height() const{ return height; }
    [[nodiscard]] int get_width() const{ return width; }
    [[nodiscard]] SDL_Renderer * get_renderer() const {  return renderer;}

private:
    int height;     // Height of the window
    int width;      // Width of the window
    SDL_Renderer *renderer = nullptr;      // Pointer for the renderer
    SDL_Window *window = nullptr;      // Pointer for the window
};


int main(int argc, char * argv[]){

    Animation fw(200, 400);
    SDL_Event event;    // Event variable

    while(event.type != SDL_QUIT){

        //down
        for (int i = 0; i < fw.get_height(); ++i) {
            SDL_Delay(10);  // setting some Delay
            SDL_PollEvent(&event);  // Catching the poll event.
            SDL_SetRenderDrawColor(fw.get_renderer(),0,0,0,0);
            SDL_RenderClear(fw.get_renderer());
            fw.Draw_Circle(fw.get_width()/2,i,25);
        }
        // up
        for (int i = fw.get_height(); i > 0; --i) {
                SDL_Delay(10);  // setting some Delay
                SDL_PollEvent(&event);  // Catching the poll event.
                SDL_SetRenderDrawColor(fw.get_renderer(),0,0,0,0);
                SDL_RenderClear(fw.get_renderer());
                fw.Draw_Circle(fw.get_width()/2,i,25);
        }


    }
    
}
