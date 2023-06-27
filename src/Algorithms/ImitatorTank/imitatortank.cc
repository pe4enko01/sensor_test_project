#include <sstream>
#include <UniSetActivator.h>
#include <UHelpers.h>
#include "ImitatorTank.h"
// -----------------------------------------------------------------------------
using namespace uniset;
using namespace std;
// -----------------------------------------------------------------------------
int main( int argc, char **argv )
{
	try
	{
		auto conf = uniset_init(argc, argv);
		
		auto act = UniSetActivator::Instance();

		auto cp1 = uniset::make_object<ImitatorTank>("ImitatorTank", "ImitatorTank");
        //auto cp2 = uniset::make_object<ImitatorTank>("ImitatorTank2", "ImitatorTank");
		act->add(cp1);
        //act->add(cp2);

		SystemMessage sm(SystemMessage::StartUp); 
		act->broadcast( sm.transport_msg() );

		cout << "\n\n\n";
		cout << "(main): -------------- ImitatorTank START -------------------------\n\n";
		act->run(false);
		return 0;
	}
	catch( SystemError& err )
	{
		cerr << "(controlprocess): " << err << endl;
	}
	catch( Exception& ex )
	{
		cerr << "(controlprocess): " << ex << endl;
	}
	catch(...)
	{
		cerr << "(controlprocess): catch(...)" << endl;
	}

	return 1;
}
// -----------------------------------------------------------------------------
