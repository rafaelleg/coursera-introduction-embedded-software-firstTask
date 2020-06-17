#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "stats.h"

int main(){
	unsigned char  	serie[ NUMBER_OF_ELEMENTS ];
	uint8_t 		forCounter;

	// Generating Series...
	for( forCounter = 0 ; forCounter < NUMBER_OF_ELEMENTS ; forCounter++ ){
		serie[ forCounter ] = rand();
	}
	sort_array( &serie[ 0 ], NUMBER_OF_ELEMENTS );
	print_array( &serie[ 0 ], NUMBER_OF_ELEMENTS );
	print_statistics( &serie[ 0 ] );
	printf( "\n\n\n\n\n" );
	
	return 0;
}

void print_statistics( unsigned char* numberSeries ){
	printf( "\n\n=============================  Statistics:  =============================\n\n" );
	printf( "Max:\t %d\n", find_maximum( &numberSeries[ 0 ], NUMBER_OF_ELEMENTS ) );
	printf( "Min:\t %d\n", find_minimum( &numberSeries[ 0 ], NUMBER_OF_ELEMENTS ) );
	printf( "Mean:\t %d\n", find_mean( &numberSeries[ 0 ], NUMBER_OF_ELEMENTS ) );
	printf( "Median:\t %d\n", find_median( &numberSeries[ 0 ], NUMBER_OF_ELEMENTS ) );
}

void print_array( unsigned char* numberSeries, uint16_t length ){
	uint8_t forCounter;

	printf( "\n\n\n\n\n=============================  Serie( dataset ):  =============================\n" );
	for( forCounter = 0 ; forCounter < length ; forCounter++ ){
		printf( "%d\n", numberSeries[ forCounter ] );
	}

}

unsigned char find_mean( unsigned char* numberSeries, uint16_t length ){
	uint16_t forCounter;
	uint16_t sum;

	// Initialization...
	sum = 0;
	
	// Computing the sum of all elements on array;
	for( forCounter = 0 ; forCounter <  length ; forCounter++ ){
		sum += numberSeries[ forCounter ];
	}

	// Dividing by the number of elements in array
	return round( (double)sum / (double)length );
}

unsigned char find_median( unsigned char* numberSeries, uint16_t length ){
	uint16_t 	middleIndex;

	// Reorganizing the array in a decrease order...
	sort_array( numberSeries, NUMBER_OF_ELEMENTS );

	// If the number of elements on array is even...
	middleIndex = ( IS_EVEN( length )? ( (uint16_t)( length / 2 ) - 1 ) : ( (uint16_t)( length / 2 ) ) );
	return find_mean( &numberSeries[ middleIndex ], ( IS_EVEN( length )? 2 : 1 ) );
}


unsigned char find_maximum( unsigned char* numberSeries, uint16_t length ){
	unsigned char 		maxNumber;
	uint16_t	forCounter;

	// Initialization...
	maxNumber = numberSeries[ 0 ];
	

	for( forCounter = 0 ; forCounter < ( length - 1 ) ; forCounter++ ){
		maxNumber = MAX_BETWEEN_TWO_NUMBERS( maxNumber, numberSeries[ forCounter + 1 ] );
	}

	// Or as the array is decreasing organized the max number is the first element of the array...
	return maxNumber;
}

unsigned char find_minimum( unsigned char* numberSeries, uint16_t length ){
	unsigned char 		minNumber;
	uint16_t	forCounter;

	// Initialization...
	minNumber = numberSeries[ 0 ];
	
	for( forCounter = 0 ; forCounter < ( length - 1 ) ; forCounter++ ){
		minNumber = MIN_BETWEEN_TWO_NUMBERS( minNumber, numberSeries[ forCounter + 1 ] );
	}

	// Or as the array is decreasing organized the min number is the last element of the array...
	return minNumber;
}

void sort_array( unsigned char* numberSeries, uint16_t length ){
	uint8_t 	someNumberIsOutOfOrder;
	unsigned char		reorderAux; 
	uint8_t 	forCounter;

	// Initialization...
	someNumberIsOutOfOrder = FALSE;

	for( forCounter = 0 ; forCounter < ( length - 1 ) ; forCounter++ ){
		if( numberSeries[ forCounter ] < numberSeries[ forCounter + 1 ] ){
			reorderAux = numberSeries[ forCounter ];
			numberSeries[ forCounter ] = numberSeries[ forCounter + 1 ];
			numberSeries[ forCounter + 1 ] = reorderAux;
			someNumberIsOutOfOrder = TRUE;
		}
	}

	if( someNumberIsOutOfOrder == TRUE ){
		sort_array( numberSeries, length );
	}
	
	return;
}