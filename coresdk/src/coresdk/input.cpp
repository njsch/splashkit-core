//
//  input.cpp
//  splashkit
//
//  Created by Andrew Cain on 15/07/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//

#include "input.h"

#include "input_driver.h"
#include "sk_input_backend.h"
#include "geometry.h"

#include <vector>
#include <iostream>
using namespace std;

struct key_down_data
{
    int code;
    int keyChar;
};

static vector<key_down_data> _keys_down;
static vector<int> _keys_just_typed; // i.e. those that have just gone down
static vector<int> _keys_released; // i.e. those that have just gone down
bool _key_pressed = false;
bool _mouse_button_clicked[6] = { false };
vector_2d _wheel_scroll = {0,0};


void quit()
{
    _sk_quit = true;
}

void _handle_key_down_callback(int code)
{
    cout << "key down: " << code << endl;
}

void _handle_key_up_callback(int code)
{
    cout << "key up: " << code << endl;
}

void _process_mouse_up_event(int code)
{
    cout << "mouse up: " << code << endl;
}

void process_mouse_wheel_callback(int x, int y)
{
    cout << "mouse wheel: " << x << ":" << y << endl;
}

void handle_input_text_callback(char *input)
{
    cout << "input text: " << input << endl;
}

void handle_window_resize(pointer p, int width, int height)
{
    cout << "resize: " << width << "x" << height << endl;
}

void handle_window_move(pointer p, int x, int y)
{
    cout << "move: " << x << ":" << y << endl;
}

void process_events()
{
    // Ensure callbacks are registered
    if( ! _input_callbacks.do_quit )
    {
        _input_callbacks.do_quit              = &quit;
        _input_callbacks.handle_key_down      = &_handle_key_down_callback;
        _input_callbacks.handle_key_up        = &_handle_key_up_callback;
        _input_callbacks.handle_mouse_up      = &_process_mouse_up_event; // click occurs on up
        _input_callbacks.handle_mouse_down    = nullptr;
        _input_callbacks.handle_mouse_wheel   = &process_mouse_wheel_callback; // click occurs on up
        _input_callbacks.handle_input_text    = &handle_input_text_callback;
        _input_callbacks.handle_window_resize = &handle_window_resize;
        _input_callbacks.handle_window_move   = &handle_window_move;
    }

    sk_process_events();
}

bool quit_requested()
{
    return _sk_quit;
}

void reset_quit()
{
    _sk_quit = false;
}
