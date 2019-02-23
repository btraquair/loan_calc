// Benjamain Traquair
//

#include <iostream>
#include "loan.hpp"


Loan::Loan(double init_balance, double init_interest)
{
    balance = init_balance;
    interest_rate = init_interest;
    if(balance > 0)
    {
        paid_in_full = false;
    }
}

double Loan::get_balance(void) const
{
    return balance;
}

double Loan::get_interest(rate_type rate_time) const
{ // 
    switch(rate_time)
    {
        case annual:
            return interest_rate;
        case monthly: 
            return interest_rate/12;
        case weekly:
            return interest_rate/52;
        case daily:
            return interest_rate/365;
    }
}

bool Loan::get_paid_state() const
{
    return paid_in_full;
}

double Loan::make_payment(double payment_amount)
{
    if(balance > 0)
    {
        balance = balance - payment_amount;
        if(balance <= 0)
        {
            paid_in_full = true;
            if(balance < 0)
            {
                //return balance*(-1);  // return "change" in case of overpayment and set balance to zero
                balance = 0;
            }

        }
    }
    return 0;
}

void Loan::compound_interest(rate_type rate_time)  // Compound interest and add to total balance. Time scales vary interest rate.
{
    double temp_int_rate;
    switch(rate_time)
    {
        case annual:
            temp_int_rate = interest_rate;
            break;
        case monthly: 
            temp_int_rate = interest_rate/12;
            break;
        case weekly:
            temp_int_rate = interest_rate/52;
            break;
        case daily:
            temp_int_rate = interest_rate/365;
            break;
    }
    if(balance > 0)
    {
        balance = balance*temp_int_rate + balance;
    }
}

double calc_min_payment(const Loan& my_loan )
{
    double min_payment = 0.0;
    min_payment = 0.1*my_loan.get_balance();
    min_payment += my_loan.get_balance()*my_loan.get_interest(Loan::monthly);

    return min_payment;

}

bool all_paid_off(const std::vector<Loan>& loan_vec)
{
    bool paid_in_full_all = (loan_vec.at(0)).get_paid_state();
    if( loan_vec.size() > 1)
    {
        for(int i = 1; i < loan_vec.size(); i++)
        {
            paid_in_full_all = paid_in_full_all && loan_vec.at(i).get_paid_state();
        }
    }
    return paid_in_full_all;

}