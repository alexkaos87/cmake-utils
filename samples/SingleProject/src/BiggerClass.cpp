#include "BiggerClass.h"

#include <iostream>
#include <algorithm>

BiggerClass::BiggerClass()
{
    std::cout << "BiggerClass c-tor\n";
}

BiggerClass::~BiggerClass()
{
    std::cout << "BiggerClass d-tor\n";
}

unsigned BiggerClass::CalculateFactorial( const unsigned number ) const
{
    return number > 1 ? CalculateFactorial(number-1) * number : 1;
}

std::string BiggerClass::CalculateOwner(const std::string& numbers) const
{
    if (!std::all_of(numbers.cbegin(), numbers.cend(), [](char c) { return std::isdigit(c); })) 
    {
        return "Unknown";
    }
    
    const auto length{numbers.size()};
    
    if (numbers[0] == '4' && (length == 13 || length == 16)) 
    {
        return "VISA";
    }
    
    if (length == 15) 
    {
        const auto prefix = numbers.substr(0, 2);
        if (prefix == "34" || prefix == "37") {
            return "AMEX";
        }
    } 

    else if (length == 16) 
    {
        if (std::equal(numbers.cbegin(), numbers.cbegin() + 4, "6011")) 
        {
            return "Discover";
        }
        
        if (numbers[0] == '5' && numbers[1] >= '1' && numbers[1] <= '5') 
        {
            return "Mastercard";
        }
    }
    
    return "Unknown";
}