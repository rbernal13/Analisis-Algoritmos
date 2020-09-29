/**
 * 
 */
package otherSorts;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

/**
 * @author Richy
 *
 */
public class BucketSort {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("BucketSort");
		
		int[] arr = new int[100000];
		long tInicio = 0,tFinal = 0;
		double tiempo = 0;
		
		
        for(int i = 0; i<arr.length;i++){
            arr[i] = (int) (Math.random() * 100);
        }
		
        //System.out.println("Secuencia Original: " +Arrays.toString(arr));
        System.out.println("Tamaño de la instancia: " + arr.length);
        
        tInicio = System.nanoTime();
		arr = bucketSortM(arr, arr.length);
		tFinal = System.nanoTime();
		
		tiempo = (tFinal - tInicio);
		
		//System.out.println("\nSecuencia Ordenada: " +Arrays.toString(arr));
		System.out.println("Tiempo de ejecucion: " + tiempo + " ns");
		
//		double tiempoConvertido = (double) tiempo / 1_000_000_000;
//		System.out.println("Tiempo de ejecucion: " + tiempoConvertido + " s");
	}

	/**
	 * @param arr
	 * @param n
	 * @return
	 */
	private static int[] bucketSortM(int[] arr, int n) {
		// TODO Auto-generated method stub
		if (n <= 0) {
			return arr;
		}
		
		List<Integer>[] buckets = new List[n];
		float maxValor = maxValue(arr);
		float divisor = maxValor / n;
		
		for (int i = 0; i < n; i++) {
			buckets[i] = new LinkedList<>();
		}
		
		for (int i = 0; i < n; i++) {
			int index = (int) (arr[i] / divisor);
			if (index != n) {
				buckets[index].add(arr[i]);
			}else {
				buckets[n - 1].add(arr[i]);
			}
			
		}
		
//		for (List<Integer> bucket : buckets) {
//			System.out.print("Casillero: " +bucket.toString() + " , " );
//		}
		
		for (int i = 0; i < n; i++) {
			Collections.sort((buckets[i]));
		}
		
		int i = 0;
		for (List<Integer> bucket: buckets) {
			for (int num : bucket) {
				arr[i++] = num;
			}
		}
		
		return arr;
	}

	/**
	 * @param arr
	 * @return
	 */
	private static int maxValue(int[] arr) {
		// TODO Auto-generated method stub
		int max_valor = 0;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] > max_valor) {
				max_valor = arr[i];
			}
		}
		return max_valor;
	}

}
