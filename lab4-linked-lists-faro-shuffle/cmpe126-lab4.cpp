#include <iostream>
#include <fstream>
#include <string>
#include "linkedList.h"
#include "card.h"

using namespace std;

void fillDeck(LinkedList<Card>& deck) {
    if (!deck.isEmpty()) {
        return;
    }
    Suit suits[4] = {Suit::CLUBS, Suit::DIAMONDS, Suit::HEARTS, Suit::SPADES};

    for (int suitIndex = 0; suitIndex < 4; suitIndex++) {
        Suit currentSuit = suits[suitIndex];
        for (int rankNumber = 2; rankNumber <= 14; rankNumber++) {
            Rank currentRank = static_cast<Rank>(rankNumber);
            Card newCard(currentRank, currentSuit);
            deck.append(newCard);
        }
    }
}

int length(LinkedList<Card>& deck) {
    return deck.getCount();
}

void printDeck(LinkedList<Card>& deck, ostream& targetFile) {
    targetFile << "Deck (" << length(deck) << "): ";

    LinkedListNode<Card>* cur = deck.getHead();
    while (cur != nullptr) {
        string* cardText = cur->elt.toString();
        targetFile << *cardText << " ";
        delete cardText;
        cur = cur->next;
    }
    targetFile << endl;
}


LinkedListNode<Card>* merge(LinkedListNode<Card>* pile1, LinkedListNode<Card>* pile2) {
    if (pile1 == nullptr) {
        return pile2;
    }
 
    LinkedListNode<Card>* a = pile1;
    LinkedListNode<Card>* b = pile2;
 
    while (a != nullptr && b != nullptr) {
        LinkedListNode<Card>* aNext = a->next;
        LinkedListNode<Card>* bNext = b->next;
        a->next = b;
        if (aNext != nullptr) {
            b->next = aNext;
        }
        a = aNext;
        b = bNext;
    }
    return pile1;
}

void faro_shuffle(LinkedList<Card>& deck, bool in_shuffle) {
    int n = length(deck);
    if (n < 2) {
        return;
    }
    int half = (n + 1) / 2; 

    LinkedListNode<Card>* top = deck.getHead();
    LinkedListNode<Card>* lastOfTop = top;
 

    for (int i = 1; i < half; i++) {
        lastOfTop = lastOfTop->next;
    }
 
    LinkedListNode<Card>* bottom = lastOfTop->next;
    lastOfTop->next = nullptr;
 
    LinkedListNode<Card>* merged;
    if (in_shuffle) {
        merged = merge(bottom, top);
    }
    else {
        merged = merge(top, bottom);
    }
 
    deck.setHead(merged);
}

int shuffleUntilRestored(bool in_shuffle, const string& fileName) {
    ofstream out(fileName);
    if (!out) {
        cout << "Could not open " << fileName << endl;
        return -1;
    }
 
    LinkedList<Card> deck;
    fillDeck(deck);
    LinkedList<Card> original(deck);
 
    int shuffleCount = 0;
    do {
        faro_shuffle(deck, in_shuffle);
        shuffleCount++;
 
        out << "After shuffle " << shuffleCount << endl;
        printDeck(deck, out);
    } while (!deck.equals(original));
 
    return shuffleCount;
}
 
int main() {
    //task 3: out shuffles
    int outCount = shuffleUntilRestored(false, "outShuffle.txt");
    //task 4 in shuffles
    int inCount = shuffleUntilRestored(true, "inShuffle.txt");
 
    if (outCount < 0 || inCount < 0) {
        return 1;
    }
 
    cout << "Out shuffles count to restore the deck: " << outCount << endl;
    cout << "In shuffles count to restore the deck: " << inCount << endl;
    return 0;
}