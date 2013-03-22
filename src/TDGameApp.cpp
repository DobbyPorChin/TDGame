#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TDGameApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void TDGameApp::setup()
{
}

void TDGameApp::mouseDown( MouseEvent event )
{
}

void TDGameApp::update()
{
}

void TDGameApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( TDGameApp, RendererGl )
