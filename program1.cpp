#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <stdexcept>

struct Node {
    double value;
    Node* next;
    Node(double v, Node* n = nullptr) : value(v), next(n) {}
};

class LinkedStack {
private:
    Node* top_;
    int count_;

public:
    LinkedStack() : top_(nullptr), count_(0) {}
    ~LinkedStack() { clear(); }

    void push(double v) {
        top_ = new Node(v, top_);
        ++count_;
    }

    bool pop(double& out) {
        if (!top_) return false;
        Node* temp = top_;
        out = top_->value;
        top_ = top_->next;
        delete temp;
        --count_;
        return true;
    }

    int size() const { return count_; }

    void clear() {
        while (top_) {
            Node* temp = top_;
            top_ = top_->next;
            delete temp;
        }
        count_ = 0;
    }
};

static bool isOperator(const std::string& tok) {
    return tok == "+" || tok == "-" || tok == "*" || tok == "/";
}

static bool tryParseDouble(const std::string& tok, double& out) {
    try {
        size_t idx = 0;
        out = std::stod(tok, &idx);
        return idx == tok.size();
    } catch (...) {
        return false;
    }
}

static std::string formatDouble(double x) {
    std::ostringstream oss;
    oss << std::setprecision(15) << std::noshowpoint << x;
    std::string s = oss.str();

    auto dotPos = s.find('.');
    if (dotPos != std::string::npos) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
        if (s.empty() || s == "-") s += "0";
    }
    return s;
}

int main() {
    std::string line;

    while (true) {
        if (!std::getline(std::cin, line)) break;
        if (line == "0") break;

        LinkedStack st;
        bool error = false;
        std::string errorMsg;

        std::istringstream iss(line);
        std::string tok;
        bool sawEquals = false;

        while (iss >> tok) {
            if (tok == "=") {
                sawEquals = true;
                break;
            }

            if (isOperator(tok)) {
                double b = 0.0, a = 0.0;
                if (st.size() < 2) {
                    error = true;
                    errorMsg = "Error: Too many operators";
                    break;
                }
                st.pop(b);
                st.pop(a);

                if (tok == "+") st.push(a + b);
                else if (tok == "-") st.push(a - b);
                else if (tok == "*") st.push(a * b);
                else if (tok == "/") {
                    if (b == 0.0) {
                        error = true;
                        errorMsg = "Error: Division by zero";
                        break;
                    }
                    st.push(a / b);
                }
            } else {
                double val = 0.0;
                if (!tryParseDouble(tok, val)) {
                    error = true;
                    errorMsg = "Error: Invalid token";
                    break;
                }
                st.push(val);
            }
        }
        if (error) {
            std::cout << errorMsg << "\n";
            continue;
        }
        if (!sawEquals) {
            std::cout << "Error: Too many operands\n";
            continue;
        }
        if (st.size() > 1) {
            std::cout << "Error: Too many operands\n";
            continue;
        }
        if (st.size() == 0) {
            std::cout << "Error: Too many operators\n";
            continue;
        }

        double result = 0.0;
        st.pop(result);
        std::cout << formatDouble(result) << "\n";
    }

    return 0;
}

/*
SAMPLE OUTPUT
----------------------------------------------
Input:  10 15 + =
Output: 25

Input:  10 15 - =
Output: -5

Input:  2.5 3.5 + =
Output: 6

Input:  10 0 / =
Output: Error: Division by zero

Input:  10 20 * / =
Output: Error: Too many operators

Input:  12 20 30 / =
Output: Error: Too many operands

Input:  -10 -30 - =
Output: 20

Input:  100 10 50 25 / * - -2 / =
Output: -40
----------------------------------------------
*/
