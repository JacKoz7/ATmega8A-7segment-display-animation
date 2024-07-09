#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	// dp g f e d c b a
	//   a
	// f   b
	//   g
	// e   c
	//   d   dp
	const uint8_t jh[] = {0b01110111, 0b00110111, 0b00000110, 0b01110111, 0b00000000};
	DDRD = 0xFF; // ca³y port D na wyjœcie (segmenty)
	DDRC = 0b00001111; // pierwsza po³owa portu C na wyjœcie (modu³y)

	int i = 0;
	
	while (1) {
		// Wyœwietlanie cyfr 
		for (int k = 0; k < 65; k++) { // Powtórz przez 65ms
			for (int j = 0; j < 4; j++) {
				PORTD = 0x00; // Turn off all segments
				PORTC = ~(1 << j); // wybór kolumny (cyfry)
				PORTD = jh[(i + j) % 5]; // wyœwietlenie odpowiedniej cyfry
				_delay_ms(1);
			}
		}

		// Przesuniêcie cyfr
		i = (i + 1) % 5; // przesuñ indeks, aby przejœæ do nastêpnego zestawu cyfr
	}
}