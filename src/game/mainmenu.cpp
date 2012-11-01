// This file is part of Dust Racing (DustRAC).
// Copyright (C) 2012 Jussi Lind <jussi.lind@iki.fi>
//
// DustRAC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// DustRAC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with DustRAC. If not, see <http://www.gnu.org/licenses/>.

#include "mainmenu.hpp"
#include "game.hpp"
#include "renderer.hpp"
#include "textmenuitemview.hpp"

#include <MenuItem>
#include <MenuItemAction>
#include <MenuItemView>
#include <MenuManager>

#include <MCLogger>
#include <MCSurface>
#include <MCSurfaceManager>

#include <QApplication>

class QuitAction : public MTFH::MenuItemAction
{
    //! \reimp
    void fire()
    {
        MCLogger().info() << "Quit selected from the main menu.";
        Game::instance().exitGame();
    }
};

class PlayAction : public MTFH::MenuItemAction
{
    //! \reimp
    void fire()
    {
        MCLogger().info() << "Play selected from the main menu.";
        MTFH::MenuManager::instance().pushMenu("trackSelection");
    }
};

class HelpAction : public MTFH::MenuItemAction
{
    //! \reimp
    void fire()
    {
        MCLogger().info() << "Help selected from the main menu.";
        MTFH::MenuManager::instance().pushMenu("help");
    }
};

class CreditsAction : public MTFH::MenuItemAction
{
    //! \reimp
    void fire()
    {
        MCLogger().info() << "Credits selected from the main menu.";
        MTFH::MenuManager::instance().pushMenu("credits");
    }
};

class SettingsAction : public MTFH::MenuItemAction
{
    //! \reimp
    void fire()
    {
        MCLogger().info() << "Settings selected from the main menu.";
        MTFH::MenuManager::instance().pushMenu("settings");
    }
};

MainMenu::MainMenu(std::string id, int width, int height)
: SurfaceMenu("mainMenuBack", id, width, height, Menu::MS_VERTICAL_LIST)
{
    using MTFH::MenuItem;

    const int itemHeight = height / 8;

    MenuItem * play = new MenuItem(width, itemHeight, "Play");
    play->setView(new TextMenuItemView(40, *play), true);
    play->setAction(new PlayAction, true);

    MenuItem * help = new MenuItem(width, itemHeight, "Help");
    help->setView(new TextMenuItemView(40, *help), true);
    help->setAction(new HelpAction, true);

    MenuItem * credits = new MenuItem(width, itemHeight, "Credits");
    credits->setView(new TextMenuItemView(40, *credits), true);
    credits->setAction(new CreditsAction, true);

    MenuItem * quit = new MenuItem(width, itemHeight, "Quit");
    quit->setView(new TextMenuItemView(40, *quit), true);
    quit->setAction(new QuitAction, true);

    MenuItem * settings = new MenuItem(width, itemHeight, "Settings");
    settings->setView(new TextMenuItemView(40, *settings), true);
    settings->setAction(new SettingsAction, true);

    addItem(*quit,     true);
    addItem(*credits,  true);
    addItem(*settings, true);
    addItem(*help,     true);
    addItem(*play,     true);
}
