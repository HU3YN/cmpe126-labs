#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

enum class Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum class Rank {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

struct Card {
    Rank rank;
    Suit suit;


    Card(Rank _rank = Rank::TWO, Suit _suit = Suit::CLUBS) : rank(_rank), suit(_suit) {}
    Card(const Card& input) : Card(input.rank, input.suit) {}

    bool operator==(const Card& other) {
        return(rank == other.rank && suit == other.suit);
    }

    bool operator!=(const Card & other) {
        return(!(*this == other));
    }

    std::string *toString() {
        std::string *s = new std::string("[");
        // First, print rank
        if(rank == Rank::JACK) {
            s->append("J");
        }
        else if(rank == Rank::QUEEN) {
            s->append("Q");
        }
        else if(rank == Rank::KING) {
            s->append("K");
        }
        else if(rank == Rank::ACE) {
            s->append("A");
        }
        else {
            s->append(std::to_string(static_cast<int>(rank)));
        }

        if(suit == Suit::CLUBS) {
            s->append("C");
        }
        else if(suit == Suit::DIAMONDS) {
            s->append("D");
        }
        else if(suit == Suit::HEARTS) {
            s->append("H");
        }
        else {
            s->append("S");
        }
        s->append("]");
        return s;
    }
};

#endif // CARD_H
