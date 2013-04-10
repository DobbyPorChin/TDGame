#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "Dijkstra.h"
#include "BinaryHeap.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TDGameApp : public AppBasic {
	public:
		void setup();
		void mouseDown( MouseEvent event );	
		void update();
		void draw();

	private:
		BinaryHeap<Grid> binaryHeap;
		Dijkstra dijkstra;
		std::vector<Grid*> path;
		string result;          // string which will contain the result
		Grid output;
		ostringstream convert;   // stream used for the conversion
};

void TDGameApp::setup()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	path = dijkstra.findPath(0, 0, 0);

	while (path.size() != 0) {
		Grid* grid = path.back();
		convert << grid->getX() << std::setw(5) << grid->getY() << std::endl;
		path.pop_back();
	}
	result = convert.str(); // set 'Result' to the contents of the stream
	
	//binaryHeap.insert(Grid(0, 0, 0));
	//binaryHeap.insert(Grid(1, 11, 1));
	//binaryHeap.insert(Grid(2, 22, 2));
	//binaryHeap.insert(Grid(3, 33, 3));
	//binaryHeap.insert(Grid(4, 44, 4));
	//binaryHeap.insert(Grid(5, 55, 5));
	//binaryHeap.insert(Grid(6, 66, 6));
	//binaryHeap.insert(Grid(7, 77, 7));



	//OutputDebugStringW(L"My output string.");
}

void TDGameApp::mouseDown( MouseEvent event )
{
}

void TDGameApp::update()
{
	//while (!binaryHeap.isEmpty()){
		
	//	output = binaryHeap.popMin();
	//	convert << output.getX() << std::setw(5) << output.getY() << std::endl;      // insert the textual representation of 'Number' in the characters in the stream

	//}
	
	//result = convert.str(); // set 'Result' to the contents of the stream
}

void TDGameApp::draw()
{
	gl::drawString( result, Vec2f(5,5), Color(1,1,1), Font("Calibri", 50));
}

CINDER_APP_BASIC( TDGameApp, RendererGl )
