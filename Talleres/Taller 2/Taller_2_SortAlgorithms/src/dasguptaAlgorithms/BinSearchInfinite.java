/**
 * 
 */
package dasguptaAlgorithms;

import java.util.Arrays;

/**
 * @author Richy
 *
 */
public class BinSearchInfinite {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Ejercicio 2.16");
		
		int arr[] = new int[20], result[] = new int[arr.length], pos, res;
		
		int arr1[] = {1, 2, 23, 24, 26, 34, 35, 44, 46, 50, 52, 61, 66, 67, 71, 72, 73, 79, 85, 93};
		
		for(int i = 0; i <  arr.length; i++) {
            arr[i] = (int)(Math.random() * 100);
        }
		
		Arrays.parallelSort(arr);
		
		System.out.println("Secuencia Original: " +Arrays.toString(arr1));
		
		pos = arr1[arr1.length-1];
		System.out.println(pos);
		
		
		res = binSearchInfinite(arr1,pos);
		
		System.out.println("BinSearch: " + res);

	}

	private static int binSearchInfinite(int[] arr, int i) {
		int pivote = (int)(arr.length/2);
		
		if (arr[pivote] == i) {
			return arr[pivote];
		}else if (arr[pivote] < i) {
			return binSearchInfinite(Arrays.copyOfRange(arr, pivote+1, arr.length), i);
		}else {
			return binSearchInfinite(Arrays.copyOfRange(arr, 0, pivote), i);
		}
	}

}
