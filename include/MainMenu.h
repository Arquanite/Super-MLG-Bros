#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <string>
#include <math.h>

using namespace sf;
class MainMenu{
private:
    RenderWindow *window;
    Texture MLGarioTexture;
    Texture SWAGlassesTexture;
    Texture BrickTexture;
    Texture LogoTexture;
    Texture PlayTexture;
    Texture ExitTexture;
    Texture CloudTexture;
    Texture RifleTexture;
    Texture JointTexture;
    Texture LoominatiTexture;
    Texture ExplosionTexture;
    Sprite MLGario;
    Sprite SWAGlasses;
    Sprite Floor;
    Sprite Logo;
    Sprite Play;
    Sprite Exit;
    Sprite Cloud1;
    Sprite Cloud2;
    Sprite Rifle;
    Sprite Joint;
    Sprite Loominati1;
    Sprite Loominati2;
    Sprite Loominati3;
    Sprite Loominati4;
    Sprite Loominati5;
    Sprite Explosion;
    Music MLGarioMusic1;
    Music MLGarioMusic2;
    Text FPS;
    Font Noto;
    View view;
    int FrameCounter = 0;
    float Interval = 0;
    float AnimationInterval = 0;
    const float AnimationSpeed = 0.1;
    const float ExplosionSpeed = 0.05;
    int AnimationFrame = 0;
    float Delay = 0;
    bool CanZoom = true;
public:
    MainMenu(RenderWindow *render_window);
    ~MainMenu();
    void Draw();
    void Update(double dt);
    int Start();
};
