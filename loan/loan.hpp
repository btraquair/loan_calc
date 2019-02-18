#ifndef LOAN_HPP
#define LOAN_HPP

#include <vector>

class Loan
{
    public:
    enum rate_type
    {
        annual, monthly, weekly, daily
    };
    Loan(double init_balance, double init_interest);
    double get_balance(void) const;
    double get_interest(rate_type rate_time) const;
    bool get_paid_state() const;
    double make_payment(double payment_amount);
    void compound_interest(rate_type rate_time);

    private:
    double interest_rate;
    double balance;
    bool paid_in_full;

};

bool all_paid_off(const std::vector<Loan>& loan_vec);


#endif