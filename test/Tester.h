#ifndef TESTER_H
#define TESTER_H

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/MacrosFinder.h"

class MacrosFinderTester : public CppUnit::TestCase
{
	public:
		void CheckTester1() 
		{
		};
		void CheckTester2() 
		{
		};
		
		CPPUNIT_TEST_SUITE( MacrosFinderTester );
		CPPUNIT_TEST( CheckTester1 );
		CPPUNIT_TEST( CheckTester2 );
		CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION( MacrosFinderTester );

#endif