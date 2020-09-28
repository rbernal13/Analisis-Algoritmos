/**
 * 
 */
package basicSorts;

import java.util.Arrays;

/**
 * @author Richy
 *
 */
/**
 * @author user
 *
 */
public class MergeSort_V2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr1[] = new int[100000];
		long tInicio = 0,tFinal = 0;
		double tiempo = 0;
		
		for(int i = 0; i <  arr1.length; i++) {
            arr1[i] = (int)(Math.random() * 1000);
        }
		
		System.out.println("Tamaño de la instancia: " + arr1.length);
		//System.out.println("Secuencia Original: " +Arrays.toString(arr1));
		
		tInicio = System.nanoTime(); 
		mergeSort(arr1,0,arr1.length - 1);
		tFinal = System.nanoTime();
		
		tiempo = (tFinal - tInicio);
		
		//System.out.println("Secuencia Ordenada: " +Arrays.toString(arr1));
		System.out.println("Tiempo de ejecucion: " + tiempo + " ns");
		
		double tiempoConvertido = (double) tiempo / 1_000_000_000;
		System.out.println("Tiempo de ejecucion: " + tiempoConvertido + " s");
		
//		for (int i : arr1) {
//			System.out.println("pos"+ i + " " +  arr1[i] + ",");
//		}
	}

	
	/**
	 * @param arr1 - Secuencia Original para ordenar
	 * @param begin - Inicio o cabeza de la secuencia
	 * @param end - Final o cola de la secuencia
	 */
	private static void mergeSort(int[] arr1, int begin, int end) {
		
		if (end <= begin) return;
		
		if (begin < end) {
			int pivot = (begin+end)/2;
			mergeSort(arr1, begin, pivot);
			mergeSort(arr1, pivot+1, end);
			merge(arr1,begin,pivot,end);
		}
	}

	
	/**
	 * @param arr1 - Secuencia para ordenar (desde mergeSort)
	 * @param begin - Inicio o cabeza de la secuencia
	 * @param pivot - Punto medio de la secuencia
	 * @param end - Inicio o cabeza de la secuencia
	 */
	private static void merge(int[] arr1, int begin, int pivot, int end) {
		// TODO Auto-generated method stub
		int leftIndex = 0, rightIndex = 0, k;
		int nl,nr;
		nl = pivot - begin + 1;
		nr = end - pivot;
		
		int left[] = new int[nl];
		int right[] = new int[nr];
		
		for (int i = 0; i < nl; i++) {
			left[i] = arr1[begin + i];
		}
		
		for (int j = 0; j < nr; j++) {
			right[j] = arr1[pivot + 1 + j];
		}
		
		k = 1;
		//int i = 0, j = 0;
		
		for (int i = begin; i < end + 1; i++) {
	        // If there are still uncopied elements in R and L, copy minimum of the two
	        if (leftIndex < left.length && rightIndex < right.length) {
	            if (left[leftIndex] < right[rightIndex]) {
	            	arr1[i] = left[leftIndex];
	            	leftIndex++;
	            } else {
	            	arr1[i] = right[rightIndex];
	                rightIndex++;
	            }
	        } else if (leftIndex < left.length) {
	            // If all elements have been copied from rightArray, copy rest of leftArray
	            arr1[i] = left[leftIndex];
	            leftIndex++;
	        } else if (rightIndex < right.length) {
	            // If all elements have been copied from leftArray, copy rest of rightArray
	            arr1[i] = right[rightIndex];
	            rightIndex++;
	        }
	    }
	}//Fin Funcion

}
