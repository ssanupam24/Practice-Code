#include <iostream>
#include <bits/stdc++.h>

template<typename RT, typename T1, typename T2>
RT max(T1 value1, T2 value2) {
    return value1 > value2;
}

int main() {
    std::cout<<::max<double>(4, 7.2);
    return 0;
}