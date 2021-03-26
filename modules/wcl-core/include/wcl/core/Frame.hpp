/*
 * The MIT License (MIT)
 *
 * Copyright � 2021 Felipe Apablaza C.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the �Software�), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons 
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED �AS IS�, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#pragma once 

#include <cassert>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <optional>
#include <functional>

namespace wcl::core {
    class MenuBar;
    class Control;
    class Frame {
    public:
        Frame(const std::wstring &title);

        ~Frame();

        void create();

        void show();

        void hide();

        void setVisible(const bool visible);

        bool isVisible() const;

        template<typename ControlT, class... Args>
        ControlT* createChild(Args&&... args) {
            ControlT *control = new ControlT(std::forward<Args>(args)...);

            addChildImpl(control);

            return control;
        }

        MenuBar* getMenuBar();

    protected:
        void addChildImpl(Control *control);
        
    private:
        struct Impl;
        std::unique_ptr<Impl> mImpl;
    };
}
