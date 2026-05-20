#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>

class Util {
public:
    static void wait(int millis) {
        std::this_thread::sleep_for(std::chrono::milliseconds(millis));
    }

    static void slowPrint(const std::string& message, int millis = 50) {
        for (char c : message) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(millis));
        }
        std::cout << std::endl;
    }
    static void slowPrint(int value, int millis = 50) {
        slowPrint(std::to_string(value), millis);
    }
    static void waitForKey() {
        std::cout << "\n[ 아무 키를 누르면 계속합니다... ]" << std::endl;
        (void)_getch();
    }
};