// Benjamain Traquair
//
#include "loan.hpp"

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

void Loan::compound_interest(rate_type rate_time)
{
    double temp_int_rate;
    switch(rate_time)
    {
        case annual:
            temp_int_rate = interest_rate;
        case monthly: 
            temp_int_rate = interest_rate/12;
        case weekly:
            temp_int_rate = interest_rate/52;
        case daily:
            temp_int_rate = interest_rate/365;
    }
    balance = balance*temp_int_rate + balance;
}