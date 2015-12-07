#include "MainMenu.h"

MainMenu::MainMenu(RenderWindow *render_window){
    window = render_window;
    int x,y;    //Temporary variables

    //PlayTexture.loadFromFile("res/Play.png");
    //ExitTexture.loadFromFile("res/Exit.png");

    //Set up clouds
    CloudTexture.loadFromFile("res/Cloud.png");
    CloudTexture.setSmooth(true);
    Cloud1.setTexture(CloudTexture);
    x = -20;
    y = 100;
    Cloud1.setPosition(x, y);
    Cloud2.setTexture(CloudTexture);
    x = window->getSize().x/2+160;
    y = 70;
    Cloud2.setPosition(x, y);

    //Set up logo
    LogoTexture.loadFromFile("res/Logo.png");
    LogoTexture.setSmooth(true);
    Logo.setTexture(LogoTexture);

    x = window->getSize().x/2;
    y = - LogoTexture.getSize().y;
    Logo.setPosition(x, y);

    x = LogoTexture.getSize().x/2;
    y = LogoTexture.getSize().y/2;
    Logo.setOrigin(x, y);

    //Set up floor
    BrickTexture.loadFromFile("res/Brick.png");
    BrickTexture.setRepeated(true);

    x = 0;
    y = window->getSize().y - BrickTexture.getSize().y * 1.5;
    Floor.setPosition(x, y);
    Floor.setTexture(BrickTexture);
    Floor.setTextureRect(IntRect(0,0, window->getSize().x, 128));

    //Set up MLGario
    MLGarioTexture.loadFromFile("res/MLGario.png");
    MLGario.setTexture(MLGarioTexture);
    MLGario.setTextureRect(IntRect(0,0,72,72));

    x = - MLGarioTexture.getSize().x;
    y = window->getSize().y - (BrickTexture.getSize().y * 1.5 + MLGarioTexture.getSize().y);
    MLGario.setPosition(x, y);
\
    //Set up rifle
    RifleTexture.loadFromFile("res/Rifle.png");
    //RifleTexture.setSmooth(true);
    Rifle.setTexture(RifleTexture);

    x = window->getSize().x;
    y = MLGario.getPosition().y + 20;
    Rifle.setPosition(x, y);

    //Set up SWAGlasses
    SWAGlassesTexture.loadFromFile("res/SWAGlasses.png");
    SWAGlassesTexture.setSmooth(true);
    SWAGlasses.setTexture(SWAGlassesTexture);

    x = window->getSize().x/3 + 10;
    y = - SWAGlassesTexture.getSize().y;
    SWAGlasses.setPosition(x, y);

    //Set up Joint
    JointTexture.loadFromFile("res/Joint.png");
    Joint.setTexture(JointTexture);
    x = window->getSize().x;
    y = window->getSize().y;
    Joint.setPosition(x, y);
    Joint.setScale(0.5, 0.5);

    //Set up FPS counter
    Noto.loadFromFile("res/NotoSans-Regular.ttf");
    FPS.setColor(Color(0,255,0));
    FPS.setPosition(0,0);
    FPS.setFont(Noto);
    FPS.setString("0 FPS");
    FPS.setCharacterSize(16);

    //Set up Loominati
    LoominatiTexture.loadFromFile("res/Iluminati.png");
    Loominati1.setTexture(LoominatiTexture);
    Loominati2.setTexture(LoominatiTexture);
    Loominati3.setTexture(LoominatiTexture);
    Loominati4.setTexture(LoominatiTexture);
    Loominati5.setTexture(LoominatiTexture);
    Loominati1.setRotation(-45);
    Loominati2.setRotation(-45);
    Loominati3.setRotation(-45);
    Loominati4.setRotation(-45);
    Loominati5.setRotation(-45);

    x = window->getSize().x/4 +200;
    y = 700;
    Loominati1.setPosition(x, y);
    Loominati2.setPosition(x+60, y-30);
    Loominati3.setPosition(x, y+50);
    Loominati4.setPosition(x, y+30);
    Loominati5.setPosition(x+200, y-65);

    Loominati2.setScale(0.7, 0.7);
    Loominati3.setScale(0.7, 0.7);
    Loominati4.setScale(0.3, 0.3);
    Loominati5.setScale(0.3, 0.3);

    //Set up explosion
    ExplosionTexture.loadFromFile("res/Explosion.png");
    Explosion.setTexture(ExplosionTexture);

    x = window->getSize().x/8;
    y = MLGario.getPosition().y -90;
    Explosion.setPosition(x,y);
    Explosion.setTextureRect(IntRect(0,0,341,162));

    //Set up doritos
    DoritosTexture.loadFromFile("res/Doritos.png");
    Doritos1.setTexture(DoritosTexture);
    Doritos2.setTexture(DoritosTexture);
    Doritos3.setTexture(DoritosTexture);
    Doritos1.setScale(0.3, 0.3);
    Doritos2.setScale(0.3, 0.3);
    Doritos3.setScale(0.3, 0.3);
    x = 200;
    y = -600;
    Doritos1.setPosition(x,y);
    Doritos2.setPosition(x+100,y+100);
    Doritos3.setPosition(x+200,y+200);

    //Set up music
    MLGarioMusic1.openFromFile("res/MarioThem.ogg");
    MLGarioMusic2.openFromFile("res/Gz.wav");
    MLGarioMusic1.play();
}

MainMenu::~MainMenu(){

}

void MainMenu::Draw(){
    window->draw(Cloud1);
    window->draw(Cloud2);
    window->draw(Loominati4);
    window->draw(Loominati5);
    window->draw(Explosion);
    window->draw(Floor);
    window->draw(MLGario);
    window->draw(SWAGlasses);
    window->draw(Rifle);
    window->draw(Joint);
    window->draw(Loominati2);
    window->draw(Loominati3);
    window->draw(Doritos1);
    window->draw(Doritos2);
    window->draw(Doritos3);
    window->draw(Logo);
    window->draw(Loominati1);
    window->draw(FPS);
}

void MainMenu::Update(double dt){
    //FPS meter
    FrameCounter++;
    Interval+=dt;
    if(Interval>= 1){
        std::string text;
        std::stringstream stream;
        stream<<FrameCounter;
        stream>>text;
        text+=" FPS";
        FPS.setString(text);
        FrameCounter = 0;
        Interval = 0;
    }

    //Logo slide animation
    if(Logo.getPosition().y < window->getSize().y/4){
        Logo.move(0, dt*90);
    }

    //MLGario run animation
    if(MLGario.getPosition().x < window->getSize().x/3){
        MLGario.move(dt*150, 0);
        AnimationInterval += dt;
        if(AnimationInterval >= AnimationSpeed){
            AnimationInterval = 0;
            AnimationFrame ++;
            if(AnimationFrame > 3) AnimationFrame = 1;
            int x = AnimationFrame*72;
            MLGario.setTextureRect(IntRect(x, 0, 72, 72));
        }
    }
    else { //Rifle animation
        if(Delay <= 1){
            AnimationInterval = 0;
            AnimationFrame = 0;
            MLGario.setTextureRect(IntRect(0, 0, 72, 72));
            Rifle.setScale(Delay, Delay);
            Rifle.setPosition(window->getSize().x/3 - 15, MLGario.getPosition().y + 25);
        }
        else if(Delay > 1 && Delay < 1.1) Rifle.setPosition(window->getSize().x, window->getSize().y);
        else if(Delay > 1.1 && Delay < 1.2) Rifle.setPosition(window->getSize().x/3 - 15, MLGario.getPosition().y + 25);
        else if(Delay > 1.2 && Delay < 1.3) Rifle.setPosition(window->getSize().x, window->getSize().y);
        else if(Delay > 1.3 && Delay < 1.4) Rifle.setPosition(window->getSize().x/3 - 15, MLGario.getPosition().y + 25);
        else if(Delay > 1.4 && Delay < 1.5) Rifle.setPosition(window->getSize().x, window->getSize().y);
        else if(Delay > 1.5 && Delay < 1.6) Rifle.setPosition(window->getSize().x/3 - 15, MLGario.getPosition().y + 25);
        //SWAGlasses animation
        else if(SWAGlasses.getPosition().y < MLGario.getPosition().y+6){
            SWAGlasses.move(0, dt*1000);
            SWAGlasses.rotate(dt*1500);
        }
        //Joint animation
        else if(Joint.getScale().x <= 1){
            int x = SWAGlasses.getPosition().x;
            int y = MLGario.getPosition().y+12;
            SWAGlasses.setPosition(x, y);
            SWAGlasses.setRotation(0);
            x = MLGario.getPosition().x + 50;
            y = MLGario.getPosition().y + 30;
            Joint.setPosition(x, y);
            Joint.setScale(Delay-2, Delay-2);
        }
        //Zoom in
        else if(window->getView().getSize().x > 240 && CanZoom){
            float x, y, w, h;
            x = 200;
            y = 400;
            w = window->getSize().x-240;
            h = window->getSize().y-180;
            float Muptiplier = (Delay-3)*3;
            view.reset(FloatRect(x*Muptiplier, y*Muptiplier, window->getSize().x-w*Muptiplier, window->getSize().y-h*Muptiplier));
            window->setView(view);
        }
        //Iluminati animation
        else if(Delay<10){
            CanZoom = false;
            int x = 7;
            Loominati1.move(-dt*90*x, -dt*90*x);
            Loominati2.move(-dt*40*x, -dt*40*x);
            Loominati3.move(-dt*50*x, -dt*50*x);
            Loominati4.move(-dt*30*x, -dt*30*x);
            Loominati5.move(-dt*40*x, -dt*40*x);
            if(Delay < 5.0) {
                int x = 280;
                int y = 100;
                Doritos1.setPosition(x,y+100);
                Doritos2.setPosition(x+100,y+500);
                Doritos3.setPosition(x-100,y+500);

               }
            if(Delay > 3.0) view.setRotation(30);
            if(Delay > 3.4) view.reset(FloatRect(185, 385, 270, 210));
            if(Delay > 3.8) view.setRotation(-45);
            if(Delay > 4.2) view.reset(FloatRect(220, 420, 220, 160));
            if(Delay > 4.6) view.setRotation(-20);
            if(Delay > 5.0) view.setRotation(10);
            if(Delay > 5.4) view.reset(FloatRect(175, 375, 290, 230));
            if(Delay > 5.8) view.setRotation(30);
            else window->setView(View(FloatRect(0,0,800,600)));
            if(Delay > 6.0) view.reset(FloatRect(220, 420, 220, 160));
            if(Delay > 6.2) view.setRotation(50);
            if(Delay > 6.4) view.setRotation(15);
            window->setView(view);
            Doritos1.move(0, +dt*400);
            Doritos2.move(-dt*400, -dt*400);
            Doritos3.move(+dt*400, -dt*400);
        }

        else window->setView(View(FloatRect(0,0,800,600)));

        if(Delay > 2.7 && AnimationFrame < 49){
            AnimationInterval+= dt;
            if(AnimationInterval >= ExplosionSpeed){
                AnimationFrame++;
                if(AnimationFrame == 49) Explosion.setTextureRect(IntRect(0,0,341,162));
                AnimationInterval = 0;
            }
            if(AnimationFrame < 8) Explosion.setTextureRect(IntRect(0,162*AnimationFrame,341,162));
            else if(AnimationFrame < 16) Explosion.setTextureRect(IntRect(341,162*(AnimationFrame-8),341,162));
            else if(AnimationFrame < 24) Explosion.setTextureRect(IntRect(682,162*(AnimationFrame-16),341,162));
            else if(AnimationFrame < 32) Explosion.setTextureRect(IntRect(1023,162*(AnimationFrame-24),341,162));
            else if(AnimationFrame < 40) Explosion.setTextureRect(IntRect(1364,162*(AnimationFrame-32),341,162));
            else if(AnimationFrame < 48) Explosion.setTextureRect(IntRect(1705,162*(AnimationFrame-40),341,162));
        }


        //Music loop
        if(MLGarioMusic1.getStatus() == SoundSource::Stopped && MLGarioMusic2.getStatus() != SoundSource::Playing){
            MLGarioMusic2.play();
        }
        Delay += dt;
    }
}

int MainMenu::Start(){
    Clock UpdateClock;
    while (window->isOpen()){
        Event event;
        while (window->pollEvent(event)){
            if (event.type == Event::Closed) window->close();
        }
        window->clear(Color(92, 148, 252));
        Update(UpdateClock.getElapsedTime().asMicroseconds()/1000000.0);
        UpdateClock.restart();
        Draw();
        window->display();
    }
}
