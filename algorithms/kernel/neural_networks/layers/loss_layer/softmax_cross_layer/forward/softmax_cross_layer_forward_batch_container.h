/* file: softmax_cross_layer_forward_batch_container.h */
/*******************************************************************************
* Copyright 2014-2016 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of the forward softmax cross layer
//--
*/

#ifndef __SOFTMAX_CROSS_LAYER_FORWARD_BATCH_CONTAINER_H__
#define __SOFTMAX_CROSS_LAYER_FORWARD_BATCH_CONTAINER_H__

#include "neural_networks/layers/loss/softmax_cross_layer.h"
#include "softmax_cross_layer_forward_kernel.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace loss
{
namespace softmax_cross
{
namespace forward
{
namespace interface1
{
template<typename algorithmFPType, Method method, CpuType cpu>
BatchContainer<algorithmFPType, method, cpu>::BatchContainer(daal::services::Environment::env *daalEnv)
{
    __DAAL_INTIALIZE_KERNELS(internal::SoftmaxCrossKernel, algorithmFPType, method);
}

template<typename algorithmFPType, Method method, CpuType cpu>
BatchContainer<algorithmFPType, method, cpu>::~BatchContainer()
{
    __DAAL_DEINTIALIZE_KERNELS();
}

template<typename algorithmFPType, Method method, CpuType cpu>
void BatchContainer<algorithmFPType, method, cpu>::compute()
{
    softmax_cross::forward::Input *input = static_cast<softmax_cross::forward::Input *>(_in);
    softmax_cross::forward::Result *result = static_cast<softmax_cross::forward::Result *>(_res);

    softmax_cross::Parameter *parameter = static_cast<softmax_cross::Parameter *>(_par);;
    daal::services::Environment::env &env = *_env;

    __DAAL_CALL_KERNEL(env, internal::SoftmaxCrossKernel, __DAAL_KERNEL_ARGUMENTS(algorithmFPType, method), compute, input, parameter,
                       result);
}
} // namespace interface1
} // namespace forward

} // namespace softmax_cross
} // namespace loss
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal

#endif
