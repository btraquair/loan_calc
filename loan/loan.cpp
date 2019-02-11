// Benjamain Traquair
//
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

double Loan::get_balance(void)
{
    return balance;
}

double Loan::get_interest(rate_type rate_time)
{
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

double Loan::make_payment(double payment_amount)
{
    balance = balance - payment_amount;
    if(balance >= 0)
    {
        paid_in_full = true;
        if(balance < 0)
        {
            return balance*(-1);  // return "change" in case of overpayment and set balance to zero
            balance = 0;
        }
        return 0;
    }
    return 0;
}

void Loan::compound_interest(rate_type rate_time)  // Compoundinterest and add to total balance. Time scales vary interest rate.
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
    balance = balance*temp_int_rate + balance;
}