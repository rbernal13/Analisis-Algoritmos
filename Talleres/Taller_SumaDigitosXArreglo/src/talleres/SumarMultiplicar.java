package talleres;

import java.util.Arrays;

/**
 * @author user
 *
 */
public class SumarMultiplicar {


	/**
	 * Main
	 * @author Richy
	 * @param args
	 */
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		long tInicio = 0, tFin = 0;
		double tiempo = 0;
		
		int numero1[] = new int[10];
		int numero2[] = new int[10];
		//int numero1[] = new int [100];
		//int numero2[] = new int [100];
		//int numero1[] = new int [1000];
		//int numero2[] = new int [1000];
		//int numero1[] = new int [2000];
		//int numero2[] = new int [2000];
		
		//int numero1[] = { 9,9,9,9,9,9,9,9,9,9 };
		//int numero2[] = { 9,9,9,9,9,9,9,9,9,9 };
		
		
		
		Arrays.fill(numero1, 9);
		Arrays.fill(numero2, 9);
		
		int resultado[] = new int[Math.max(numero1.length, numero2.length)+1];
		int producto[] = new int[Math.max(numero1.length, numero2.length)];
		
		System.out.println("Instancia de tamaño " + numero1.length);
		

//		System.out.println("Los numeros a sumar son: ");
//		System.out.println("- Numero 1: ");
//		for (int valor : numero1) {
//			System.out.print(" " + valor + " ");
//		}
//
//		System.out.println("");
//		System.out.println("- Numero 2: ");
//		for (int valor : numero2) {
//			System.out.print(" " + valor + " ");
//		}
//		System.out.println("");
		
//		SUMA
		resultado = sumar(numero1, numero2);

		System.out.println("El resultado es: ");
		for (int valor : resultado) {
			System.out.print(" " + valor + " ");
		}
		System.out.println();
		
//		MULTIPLICACION
		
		//tInicio = System.currentTimeMillis(); //Inicio de medicion del tiempo
		tInicio = System.nanoTime(); //Inicio de medicion del tiempo
		
		producto = multiplicar(numero1, numero2);
		
		//tFin = System.currentTimeMillis(); // Fin de medicion del tiempo
		tFin = System.nanoTime(); //Inicio de medicion del tiempo
		
		tiempo = (tFin - tInicio);
		
		//System.out.printf("El tiempo de ejecucion de la multiplicacion en milisegundos: %.5e", tiempo);
		System.out.println("El tiempo de ejecucion de la multiplicacion en nanosegundos: " + tiempo);
		

		System.out.println("El producto es: ");
		for (int valor : producto) {	
			System.out.print(" " + valor + " ");
		}
		System.out.println("");
		
		
	}
	
	
	private static void printArray(int [] producto) {
		for (int valor : producto) {
			System.out.print(valor);
		}
	}

	
	/**
	 * Algoritmo de Multiplicar
	 *    9 9 9 9 -> Multiplicando
	 *  x 9 9 9 9 -> Multiplicador
	 *  _________
	 *  
	 * +semiProducto
	 * __________
	 * Producto
	 * 
	 * @param multiplicando Los digitos de este numero se van a iterar o recorrer por cada digito en el multiplicador
	 * @param multiplicador 
	 * @return producto
	 */
	
	private static int[] multiplicar(int[] multiplicando, int[] multiplicador) {
		
		int[] producto = { 0 };
		
		for (int i = multiplicador.length - 1; i >= 0; i--) {
			int digito = multiplicador[i];
			int[] semiProducto = { 0 };
			for (int j = 0; j < digito; j++) {
				semiProducto = sumar(multiplicando, semiProducto); 
			}
			
			int posicion = multiplicador.length - 1 - i;
			
			semiProducto = Arrays.copyOf(semiProducto, semiProducto.length + posicion);	// Clono el arreglo y agrego una posicion a la derecha
			//La complejidad temporal de Array.copyOf es O(n) por que se trata de un loop o bucle
			
			producto = sumar(semiProducto, producto); // Cada vez que obtenga un nuevo arreglo, lo sumo con el anterior.
		}
		
		return producto;
	}


	private static int[] sumar(int[] numero1, int[] numero2) {
	
		int resul[] = new int[Math.max(numero1.length, numero2.length)+1];
		int resul_tam = resul.length - 1;
		int carry = 0, suma = 0, i=numero1.length - 1, j = numero2.length - 1;
				
		while( j >= 0 && i >= 0) {
			
			int sumando1 = i >= 0 ? numero1[i] : 0;
			int sumando2 = j >= 0 ? numero2[j] : 0;
			
			suma = sumando1 + sumando2 + carry;
			resul[resul_tam] = (suma % 10); // Se añade el digito unitario al resultado
										  //(Ex. Si es 13, la unidad es 3)
			
			carry = suma / 10; // Obtengo el carry (1 digito) para la siguiente operacion
			
			i--;
			j--; // Avanzo una posicion en el numero 2 (De atras hacia adelante)
			resul_tam--; // Avanzo una posicion en el resultado (De atras hacia adelante)


//			System.out.println("Valor Suma: " + suma);
//			System.out.println("Valor Digito: " + suma % 10);
//			System.out.println("Valor Carry: " + carry);
//			
//			System.out.println("Resultado: "+Arrays.toString(resul));
		}
		
		while (i >= 0) {
			suma = numero1[i] + carry;
			resul[resul_tam] = (suma % 10);
			carry = suma/10;
			i--;
			resul_tam--;
			//System.out.println("Resultado: "+Arrays.toString(resul));
		}
		
		if (carry > 0) {
			resul[resul_tam] = carry;
			resul_tam--;
			//System.out.println("Resultadoc: "+Arrays.toString(resul));
		}
		
//		printArray(numero1);
//		System.out.print( " + ");
//		printArray(numero2);
//		System.out.print( " = ");
//		printArray(resul);
//		System.out.println();
		
		return resul;

	}
	
}
