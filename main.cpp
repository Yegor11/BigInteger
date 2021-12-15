#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

class BigInteger
{
public:

    BigInteger() = default;

    BigInteger( const std::string& number_input )
    {
        for (auto i = number_input.rbegin()  ; i < number_input.rend() ; ++i)
        {
            if( std::isdigit(*i))
            {
                number.push_back( *i - '0' );
            }
        }
    }

    BigInteger( int number_input )
    {
        while( number_input )
        {
            number.push_back(number_input % 10);
            number_input /= 10;
        };
    }

    friend std::ostream& operator<<( std::ostream& os, const BigInteger& other )
    {
        for (auto i = other.number.rbegin()  ; i < other.number.rend() ; ++i)
        {
            os << *i ;
        }
        return os;
    }

    friend std::istream& operator>>( std::istream& is, BigInteger& other )
    {

        std::string qwerty{};
        is >> qwerty;
        BigInteger i{qwerty};
        other.number = std::move(i.number);
        return is;
    }


    BigInteger operator+( const BigInteger& other ) const
    {
        BigInteger sum;

        const size_t max_size = std::max(number.size(),other.number.size());
        sum.number.reserve( max_size + 1 );
        sum.number.resize( max_size,0 );

        int carry{0};
        for (size_t i = 0; i < max_size; ++i)
        {
            sum.number[i] += carry;
            if( i < number.size() )
            {
                sum.number[i] += number[i];
            }
            if( i < other.number.size() )
            {
                sum.number[i] +=  other.number[i];
            }
            carry = sum.number[i] / 10 ;
            sum.number[i] % 10;
        }

        if( carry )
        {
            sum.number.push_back( carry );
        }

        return sum;
    }

    BigInteger( const BigInteger& other )
    {
        number = other.number;
    }

    BigInteger( BigInteger&& other ) noexcept
    {
        number = std::move(other.number);
    }

private:
    std::vector<int> number{};
};


int main() {

    BigInteger a("121331313");
    BigInteger b(421357);

//    while(1)
//    {
//        std::cin >> a >> b;
//        std::cout << a + b;
//
//    }

    return 0;
}
