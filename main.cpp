#include <iostream>
#include "loan/loan.hpp"
//#include <boost/array.hpp>

int main()
{
    // Initialize new loan for $10,000 at 6.5%
    Loan my_loan = Loan(10000, 0.065);
    std::cout << "Hello Loans" << std::endl;
    std::cout << "Initial Balance: " << my_loan.get_balance() << std::endl;
    std::cout << "Interest rate (annual, decimal): " << my_loan.get_interest(Loan::annual) << std::endl;

    // Conmpound Interest once annually
    my_loan.compound_interest(Loan::annual);
    std::cout << "Year 1 Balance: " << my_loan.get_balance() << std::endl;
    // Make single payment of $500
    my_loan.make_payment(500);
    std::cout << "Year 1 Balance after payment: " << my_loan.get_balance() << std::endl;


    return 0;
}