#include <iostream>
#include "loan/loan.hpp"
//#include <boost/array.hpp>

int main()
{
    // Initialize new loan for $10,000 at 6.5%
    Loan my_loan = Loan(10000, 0.065);
    Loan my_loan1 = Loan(5000, 0.035);
    std::cout << "Hello Loans" << std::endl;

    
    std::vector<Loan> loan_vec;

    loan_vec.push_back(my_loan);
    loan_vec.push_back(my_loan1);
    bool full_loan_paid_state =  all_paid_off(loan_vec);
    int month = 0;
    while(!full_loan_paid_state)
    {
        for(int i = 0; i < loan_vec.size(); i++)
        {
            loan_vec.at(i).compound_interest(Loan::monthly);
            loan_vec.at(i).make_payment(500);
            std::cout << "Loan " << i << " Balance: " << loan_vec.at(i).get_balance() << " . Month: " << month << std::endl;
        }
        full_loan_paid_state = all_paid_off(loan_vec);
        month++;
        if(month == 25)
        {
            std::cout << "It didnt work" << std::endl;
            full_loan_paid_state = true;  // Set false success criteria to break out of loop
        }
    }



    return 0;
}