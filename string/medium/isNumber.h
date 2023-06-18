//
// Created by 94817 on 2023/6/17.
//

#pragma once

#include <string>
#include <unordered_map>

class Solution {
public:
    bool isNumber(std::string s) const {
        auto cur_state = STATE_START_SPACE;
        for (const auto c: s) {
            const auto type = getCharType(c);
            if (type == CHAR_INVALID) {
                return false;
            }
            if (state_transfer_[cur_state].find(type) == state_transfer_[cur_state].end()) {
                return false;
            }
            cur_state = state_transfer_[cur_state][type];
        }

        return cur_state == STATE_INTEGER || cur_state == STATE_DOT || cur_state == STATE_FRACTION ||
               cur_state == STATE_EXP_INTEGER || cur_state == STATE_END_SPACE;
    }

private:
    enum State {
        STATE_START_SPACE,
        STATE_SIGN,
        STATE_INTEGER,
        STATE_DOT,
        STATE_DOT_WITHOUT_INTEGER,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_INTEGER,
        STATE_END_SPACE,
    };

    enum CharType {
        CHAR_SPACE,
        CHAR_SIGN,
        CHAR_NUMBER,
        CHAR_DOT,
        CHAR_EXP,
        CHAR_INVALID,
    };

    static CharType getCharType(const char c) {
        if (c >= '0' && c <= '9') {
            return CHAR_NUMBER;
        }
        if (c == ' ') {
            return CHAR_SPACE;
        }
        if (c == '+' || c == '-') {
            return CHAR_SIGN;
        }
        if (c == '.') {
            return CHAR_DOT;
        }
        if (c == 'e' || c == 'E') {
            return CHAR_EXP;
        }
        return CHAR_INVALID;
    }

    static inline std::unordered_map<State, std::unordered_map<CharType, State>> state_transfer_{
            {STATE_START_SPACE,         {
                                                {CHAR_SPACE,  STATE_START_SPACE},
                                                {CHAR_SIGN,   STATE_SIGN},
                                                {CHAR_NUMBER, STATE_INTEGER},
                                                {CHAR_DOT,   STATE_DOT_WITHOUT_INTEGER},
                                        }},
            {STATE_SIGN,                {
                                                {CHAR_NUMBER, STATE_INTEGER},
                                                {CHAR_DOT,    STATE_DOT_WITHOUT_INTEGER},
                                        }},
            {STATE_INTEGER,             {
                                                {CHAR_NUMBER, STATE_INTEGER},
                                                {CHAR_DOT,    STATE_DOT},
                                                {CHAR_EXP,    STATE_EXP},
                                                {CHAR_SPACE, STATE_END_SPACE},
                                        }},
            {STATE_DOT,                 {
                                                {CHAR_NUMBER, STATE_FRACTION},
                                                {CHAR_EXP,    STATE_EXP},
                                                {CHAR_SPACE,  STATE_END_SPACE},
                                        }},
            {STATE_DOT_WITHOUT_INTEGER, {
                                                {CHAR_NUMBER, STATE_FRACTION},
                                        }},
            {STATE_FRACTION,            {
                                                {CHAR_NUMBER, STATE_FRACTION},
                                                {CHAR_EXP,    STATE_EXP},
                                                {CHAR_SPACE,  STATE_END_SPACE},
                                        }},
            {STATE_EXP,                 {
                                                {CHAR_SIGN,   STATE_EXP_SIGN},
                                                {CHAR_NUMBER, STATE_EXP_INTEGER},
                                        }},
            {STATE_EXP_SIGN,            {
                                                {CHAR_NUMBER, STATE_EXP_INTEGER},
                                        }},
            {STATE_EXP_INTEGER,         {
                                                {CHAR_NUMBER, STATE_EXP_INTEGER},
                                                {CHAR_SPACE,  STATE_END_SPACE},
                                        }},
            {STATE_END_SPACE,           {
                                                {CHAR_SPACE,  STATE_END_SPACE},
                                        }},
    };
};
