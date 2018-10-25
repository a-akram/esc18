#include <>
#include <cstdint>



__global__
void goGPU(float * r
	   ,float const * __restrict__ x
	   ,float const * __restrict__ y
	   ,float const * __restrict__ z
	   ,float const * __restrict__ w
	   ,uint32_t n
	   ) {
  int i = blockDim.x * blockIdx.x + threadIdx.x;
  if (i>=n) return;
	   
  r[i] = x[i]*y[i] + z[i]*w[i];
}


int main() {

  uint32_t N = 1024;

  float x[1024];
  float * x_d = nullptr;
  cudaMalloc(&x_d, sizeof(x));


  float r[1024];
  float * r_d = nullptr;
  cudaMalloc(&r_d, sizeof(r));

  
  cudaMemcpy(x_d, x, sizeof(r), cudaMemcpyHostToDevice);

  goGPU<<<4,256>>>(r_d,x_d,y_d,z_d,w_d,N);
  
  cudaMemcpy(r, r_d, sizeof(r), cudaMemcpyDeviceToHost);

  for ( e : r)
    std::cout << e ' ';
  std::endl;


  
}
