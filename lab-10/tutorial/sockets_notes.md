# Programowanie sieciowe - gniazda (ang. *sockets*)

## Źródło

[Sockets Tutorial](http://www.linuxhowtos.org/C_C++/socket.htm)

Gniazda służą do komunikacji międzyprocesowej i w głównej mierze są wykorzystywane w modeul komunikacji opartej o serwer i klienta. W typowym scenariuszu klient nawiązuje połączenie z serwerem w celu uzyskania konkrentej paczki danych. O ile klient musi znać adres i port serwera o tyle serwer nie musi posiadać żadnych informacji o kliencie. Jak tylko połączenie zostanie nawiązane, obie strony mogą wysyłać i otrzymywać informacje.

**Każda ze stron inicjalizuje swój własny socket.**

## Utowrzenie gniazda po stronie klienta

1. Utworzenie gniazda za pomocą wywołania `socket()`
2. Połączenie do serwera z wykorzystaniem `connect()`
3. Wysyłanie i odbieranie danych - `write()` oraz `read()`

## Utworzenie gniazda po stornie serwera

1. Utworzenie gniazda za pomocą wywołania `socket()`
2. Połączenie gniazda z IP za pomocą `bind()`. Po stronie serwera musi być jeszcze skojarzony numer portu z wybranym gniazdem.
3. Oczekiwanie na połączenie `listen()`
4. Zaakceptowanie połączenia za pomocą `accept()`
5. Wysyłanie i odbieranie danych.

## Typy gniazd

Kiedy gniazdo jest tworzone musi posiadać swój adres domenowy oraz typ gniazda. Dwa procesy mogą się komunikować tylko wtedy, jeśli typy ich gniazd są tego samego typu i są w tej samej domenie.

W systemie UNIX, adres gniazda jest stringiem, który po prostu jest ścieżką dostępu do pliku. Z kolei w internecie składa się z 32 bitów.

Dodatkowo, każde gniazdo musi posiadać swój numer portu na komputerze hostującym. Składa się z 16 bitów typu unsigned int.

Istnieją dwa typy gniazd:

- gniazda strumieniowe (ang. *stream sockets*) - ciągły strumień znaków, do komunikacji używają TCP
- datagramy (ang. *datagram sockets*) - cała wiadomość w jednym kawałku, do komunikacji używają UDP
