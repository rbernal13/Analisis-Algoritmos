/**
 * 
 */
package otherSorts;

import java.util.Arrays;

/**
 * @author user
 *
 */
public class CountingSort {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("CountingSort");
		
		int[] arr = new int[100000];
		long tInicio = 0,tFinal = 0;
		double tiempo = 0;
		
		
        for(int i = 0; i<arr.length;i++){
            arr[i] = (int) (Math.random() * 100);
        }
		
        //System.out.println("Secuencia Original: " +Arrays.toString(arr));
        System.out.println("Tamaño de la instancia: " + arr.length);
        
        tInicio = System.nanoTime();
		arr = countSort(arr, maxValue(arr));
		tFinal = System.nanoTime();
		
		tiempo = (tFinal - tInicio);
		
		//System.out.println("\nSecuencia Ordenada: " +Arrays.toString(arr));
		System.out.println("Tiempo de ejecucion: " + tiempo + " ns");
		
//		double tiempoConvertido = (double) tiempo / 1_000_000_000;
//		System.out.println("Tiempo de ejecucion: " + tiempoConvertido + " s");

	}

	private static int[] countSort(int[] arr, int maxV) {
		// TODO Auto-generated method stub
		int[] count = new int[maxV + 1];
		int[] output = new int[arr.length + 1];
		
		for (int i = 0; i < maxV; i++) {
			count[i] = 0;
		} 
  
        for (int i = 1; i < arr.length; i++) { 
            count[arr[i]]++; 
        } 
        
        for (int i = 1; i <= maxV; i++) { 
            count[i] += count[i - 1];
        }
  
        for (int i = arr.length - 1; i >= 0; i--) { 
            output[count[arr[i]] - 1] = arr[i]; 
            count[arr[i]]--; 
        } 
  
        for (int i = 0; i < arr.length; i++) { 
            arr[i] = output[i]; 
        }
        
        return arr;
	}
	
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
