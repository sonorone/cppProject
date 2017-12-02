// Final Project Milestone 2
// Version 1.0
// Date:    November 30, 2017
// Author   
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "ErrorMessage.h"

namespace sict {
    /* explicit 1 param constructor */
    ErrorMessage::ErrorMessage(const char* errorMessage) {
        if (errorMessage == nullptr) {
            addr = nullptr;
        }
        else {
            std::string s(errorMessage);
            int size = (int)s.length();
            addr = new char[size];
            strncpy(addr, errorMessage, size-1);
            addr[size] = '\n';
        }
    }
    /* deallocates dynamic memory of an ErrorMessage object */
    ErrorMessage::~ErrorMessage() {
        delete [] addr;
    }
    /* clears the state of a current object and sets to an empty state */
    void ErrorMessage::clear() {
        delete [] addr;
        addr = nullptr;
    }
    /* reports the state: true is empty state */
    bool ErrorMessage::isClear() const {
        return (addr == nullptr) ? true : false;
    }
    /* stores a copy of passed */
    void ErrorMessage::message(const char* str) {
        delete [] addr;
        addr = new char[sizeof(str)];
        copyErrorMsg(str);
    }
    /* returns message content */
    const char* ErrorMessage::message() const {
        return this->addr;
    }
    /* helper function for insertion operator */
    std::string ErrorMessage::getAddr() const {
        return addr;
    }
    /* inserts error message to the output stream */
    std::ostream& operator<<(std::ostream& os, const ErrorMessage& er) {
        if (!er.isClear()) {
            std::string s(er.getAddr());
            os << s;
        }
        return os;
    }
    
    /* my functions */
    /* copies message, warning: this func doesn't validate...
     * apply only after checking if in an empty state
     */
    void ErrorMessage::copyErrorMsg(const char* errorMessage) {
        std::string s(errorMessage);
        int size = (int)s.length();
        addr = new char[size];
        strncpy(addr, errorMessage, size-1);
        addr[size] = '\n';
    }
}
