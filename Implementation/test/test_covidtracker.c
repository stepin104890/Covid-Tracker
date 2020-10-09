#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <covidtracker.h>
#define PROJECT_NAME    "covidtracker"

void test_menu(void);
void test_display(void);
void test_casescount(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


/* Add your test functions*/
  
  CU_add_test(suite, "menu", test_menu);
  CU_add_test(suite, "display", test_display);
  CU_add_test(suite, "casescount", test_casescount);

/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}


/* Write all the test functions */

void test_menu(void) {
  CU_ASSERT(1 == valid_choice(2));
  CU_ASSERT(1 == valid_choice(5));
  CU_ASSERT(0 == valid_choice(8));
  CU_ASSERT(0 == valid_choice(9));
  
  /* Dummy fail*/
  //CU_ASSERT(1 == valid_choice(7));
  //CU_ASSERT(0 == valid_choice(3));
}

void test_display(void) {
  CU_ASSERT(1 == display());
  
  /* Dummy fail*/
  //CU_ASSERT(0 == display());
}

struct covid a={.confirmed="5000"};
struct covid b={.confirmed="123"};
struct covid c={.confirmed="0"};
struct covid d={.confirmed="abc"};

void test_casescount(void) {
  CU_ASSERT(1 == cases_count(a));
  CU_ASSERT(1 == cases_count(b));
  CU_ASSERT(1 == cases_count(c));
  CU_ASSERT(0 == cases_count(d));
  
  /* Dummy fail*/
  //CU_ASSERT(0 == display());
}


