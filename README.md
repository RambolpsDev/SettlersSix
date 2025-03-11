# SettlersSix

## Dependencies

The Game Requires The Following Dependencies:

 - SDL3
 - SSECS

### SDL3

#### What Is It?

Simple DirectMedia Layer is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL/Direct3D/Metal/Vulkan. It is used by video playback software, emulators, and many popular games.

#### How Am I Using It?

It will be used to handle basically all of the platform code for the game, such as rendering, input, sound, and much more! I am adding its GitHub as a git submodule, which allows me to compile the library alongside my game.

#### Where To Find More Info

[Website](https://wiki.libsdl.org/SDL3/FrontPage)

[Github](https://github.com/libsdl-org/SDL)

### SSECS

#### What Is It?

SEECS is a small, header-only RTTI ECS sparse set implementation for C++. SEECS stands for Simple-Enough-Entity-Component-System. The goal is to implement the core of a functional ECS using sparse sets as a resource for learning while still keeping it efficient.

#### How Am I Using It?

It will be used as the basic ECS for the game. I chose it for its simplicity above all else. Keeping it this simple gives me the ability to modify it and fully understand every part of it. To use it, I just copied the header file into my include folder.

#### Where To Find More Info

[Github](https://github.com/chrischristakis/seecs)

[Youtube](https://www.youtube.com/watch?v=yyZMoE1FAJ0)

[Website](https://chrischristakis.com/)

