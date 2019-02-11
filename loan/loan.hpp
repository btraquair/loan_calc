#ifndef LOAN_HPP
#define LOAN_HPP

class Loan
{
    public:
    enum rate_type
    {
        annual, monthly, weekly, daily
    };
    Loan(double init_balance, double init_interest);
    double get_balance(void);
    double get_interest(rate_type rate_time);
    double make_payment(double payment_amount);
    void compound_interest(rate_type rate_time);

    private:
    double interest_rate;
    double balance;
    bool paid_in_full;

};

#endif