/**
 * 
 */
package dasguptaAlgorithms;

import java.util.Arrays;

/**
 * @author user
 *
 */
public class BinSearchAlg217 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
int arr[] = new int[20], result[] = new int[arr.length], buscar, res;
		
		System.out.println("Ejercicio 2.17");

		int arr1[] = {1, 2, 23, 24, 26, 34, 35, 44, 46, 50, 52, 61, 66, 67, 71, 72, 73, 79, 85, 93};
		
//		for(int i = 0; i <  arr.length; i++) {
//            arr[i] = (int)(Math.random() * 100);
//        }
		
//		Arrays.parallelSort(arr);
		
		System.out.println("Secuencia Original: " +Arrays.toString(arr1));
		
//		buscar = arr1[arr1.length-4];
		buscar = 50;
		System.out.println("Elemento a buscar: " + buscar);
		
		
		res = binSearch(arr1, 0, arr.length, buscar);
		
		System.out.println("BinSearch -  El elemento " + buscar + " esta en la posicion " + res);

	}

	private static int binSearch(int[] arr1, int begin, int end, int buscar) {
		// TODO Auto-generated method stub
		int mid = (begin + end) / 2;
		if (end < begin) {
			return -1;
		}
		if (arr1[mid] == buscar) {
			return mid;
		}
		if (arr1[mid] > buscar) {
			return binSearch(arr1, begin, mid-1, buscar);
		}else if(arr1[mid] < buscar) {
			return binSearch(arr1, mid+1, end, buscar);
		}
		return -1;
	}

}
