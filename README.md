# Console Blackjack

Just a blackjack game 🂡 🂢 🂣 🂤 🂥

## Command line options

```
--suppress-color - Disable colors in the interface
--unicode-cards - Show unicode card symbols (🂥) instead of alphanumeric code (5S)
```

## Build

```bash
cmake . && make
```

## Game session example

```
DEALER  Score: 9        Deck: 🂩
YOU     Score: 14       Deck: 🂤 🃍

Hit or stand? (h/s): h

DEALER  Score: 9        Deck: 🂩
YOU     Score: 24       Deck: 🂤 🃍 🃚

You lose!
Win: 0. Lose: 1. Tie: 0

Do you want to play the next game?(y/n)
```
