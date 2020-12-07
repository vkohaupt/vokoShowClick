#include "QvkGlobalMouse.h"

#include <QTest>
#include <QDebug>

#include<X11/Xlib.h>
#include<stdio.h>

QvkGlobalMouse::QvkGlobalMouse()
{
  onOff = false;
}

QvkGlobalMouse::~QvkGlobalMouse()
{
}

void QvkGlobalMouse::setCursorOn()
{
  onOff = true;
}

void QvkGlobalMouse::setCursorOff()
{
  onOff = false;
}


void QvkGlobalMouse::mousePressed()
{
  Display* display;
  Window root;
  display = XOpenDisplay( NULL );
  root = DefaultRootWindow( display);
  Window root_return, child_return;
  int x, y;
  int win_x, win_y;
  unsigned int mask;
  int pressed = 0;

  while( onOff )
  {
    QCoreApplication::processEvents( QEventLoop::AllEvents );
    XQueryPointer(display, root, &root_return, &child_return, &x, &y, &win_x, &win_y, &mask);
    QTest::qSleep( 10 );

    if ( ( mask & Button1Mask) | ( mask & Button2Mask ) | ( mask & Button3Mask ) )
    {
      if ( pressed == 0 )
      {
        pressed = 1;
	emit mousePressed( win_x, win_y );
      }
    }
    else
      pressed = 0;

    fflush(stdout);
  }
  XCloseDisplay( display );
}
