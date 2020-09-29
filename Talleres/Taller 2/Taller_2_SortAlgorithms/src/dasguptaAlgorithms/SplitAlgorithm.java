/**
 * 
 */
package dasguptaAlgorithms;

import java.util.Arrays;

/**
 * @author Richy
 *
 */
public class SplitAlgorithm {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Ejercicio 2.15");
		
		int arr[] = new int[10], result[] = new int[arr.length], pos, res;
		
		//int arr1[] = {1, 2, 23, 24, 26, 34, 35, 44, 46, 50, 52, 61, 66, 67, 71, 72, 73, 79, 85, 93};
		
		for(int i = 0; i <  arr.length; i++) {
            arr[i] = (int)(Math.random() * 100);
        }
		
		System.out.println("Secuencia Original: " +Arrays.toString(arr));
		pos = arr.length / 2;
		System.out.println(pos);
		
		result = split(arr, pos);
		
		System.out.println("Secuencia despues de split: " +Arrays.toString(result));
		
	}

	private static int[] split(int[] arr1, int pos) {
		// TODO Auto-generated method stub
		int x = 0, n = arr1.length, i;
		
		for ( i = 0; i < arr1.length; i++) {
			if (arr1[i] < pos) {
				int swap = arr1[i];
				arr1[i] = arr1[x];
				arr1[x] = swap;
				x++;
			}
		}
		for (i = x; i < arr1.length; i++) {
			if (arr1[i] == pos) {
				int swap = arr1[i];
				arr1[i] = arr1[x];
				arr1[x] = swap;
				x++;
			}
		}
		
		return arr1;
	}

}
