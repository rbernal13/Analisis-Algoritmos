/**
 * 
 */
package basicSorts;

import java.util.Arrays;

/**
 * @author user
 *
 */
public class QuickSort {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr1[] = new int[100000];
		long tInicio = 0,tFinal = 0;
		double tiempo = 0;
		
		for(int i = 0; i <  arr1.length; i++) {
            arr1[i] = (int)(Math.random() * 100);
        }
		
		System.out.println("Tamaño de la instancia: " + arr1.length);
		//System.out.println("Secuencia Original: " +Arrays.toString(arr1));
		
		tInicio = System.nanoTime(); 
		quickSort(arr1,0,arr1.length - 1);
		tFinal = System.nanoTime();
		
		tiempo = (tFinal - tInicio);
		
		//System.out.println("Secuencia Ordenada: " +Arrays.toString(arr1));
		System.out.println("Tiempo de ejecucion: " + tiempo + " ns");
		
		double tiempoConvertido = (double) tiempo / 1_000_000_000;
		System.out.println("Tiempo de ejecucion: " + tiempoConvertido + " s");
		
//		for (int i : arr1) {
//			System.out.println("pos"+ i + ": " +  arr1[i] + ",");
//		}

	}

	/**
	 * @param arr1
	 * @param begin
	 * @param end
	 */
	private static void quickSort(int[] arr1, int begin, int end) {
		// TODO Auto-generated method stub
		int pivot;
		if (begin < end) {
			pivot = partition(arr1, begin, end);
			
			quickSort(arr1, begin, pivot - 1);
			quickSort(arr1, pivot + 1, end);
		}
		
	}

	/**
	 * @param arr1
	 * @param begin
	 * @param end
	 * @return
	 */
	private static int partition(int[] arr1, int begin, int end) {
		// TODO Auto-generated method stub
		int pivot = arr1[end],i,swap = 0;
		
		i = (begin - 1);
		
		for (int j = begin; j <= end; j++) {
			if (arr1[j] < pivot) {
				i++;
				swap = arr1[i]; 
                arr1[i] = arr1[j]; 
                arr1[j] = swap;
			}
		}
		
		swap = arr1[i+1]; 
        arr1[i+1] = arr1[end]; 
        arr1[end] = swap;
		
        return i + 1;
	}

}
