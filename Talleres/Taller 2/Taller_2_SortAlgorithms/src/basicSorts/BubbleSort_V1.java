/**
 * 
 */
package basicSorts;

import java.util.Arrays;

/**
 * @author Richy
 *
 */
public class BubbleSort_V1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("BubbleSort o BurbujaSort");
		
		int arr1[] = new int[100000], result[] = new int[arr1.length];
		long tInicio = 0,tFinal = 0;
		double tiempo = 0;
		
		for(int i = 0; i <  arr1.length; i++) {
            arr1[i] = (int)(Math.random() * 1000);
        }
		
		System.out.println("Tamaño de la instancia: " + arr1.length);
		//System.out.println("Secuencia Original: " +Arrays.toString(arr1));
		
		tInicio = System.nanoTime();
		result = burbujaSort(arr1,arr1.length);
		tFinal = System.nanoTime();
		
		tiempo = (tFinal - tInicio);
				
		//System.out.println("Secuencia Ordenada: " +Arrays.toString(result));
		System.out.println("Tiempo de ejecucion: " + tiempo + " ns");
		
		double tiempoConvertido = (double) tiempo / 1_000_000_000;
		
		System.out.println("Tiempo de ejecucion: " + tiempoConvertido + " s");
		
		
//		for (int i : result) {
//			System.out.println("pos"+ i + " " +  result[i] + ",");
//		}
	}
	
	
	/**
	 * 
	 * @param arr1 - Secuencia con elementos a ordenar
	 * @param n - Tamaño de la secuencia (n elementos)
	 * @return arr1 ordenado
	 */
	private static int[] burbujaSort(int[] arr1, int n) {
		// TODO Auto-generated method stub
		int swap = 0;
		for (int i = 0; i < (n - 1); i++) {
			for (int j = 0; j < (n - i - 1); j++) {
				if (arr1[j] > arr1[j+1]) {
					swap = arr1[j];
					arr1[j] = arr1[j+1];				
					arr1[j+1] = swap;
				}
				
			}
			
		}
		//System.out.println("Secuencia Ordenada: " +Arrays.toString(arr1));
		return arr1;
	}

}
