/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Soeren Sonnenburg, Evan Shelhamer
 */

#include <shogun/lib/common.h>
#include <shogun/kernel/SigmoidKernel.h>

using namespace shogun;

CSigmoidKernel::CSigmoidKernel() : CDotKernel()
{
	init();
}

CSigmoidKernel::CSigmoidKernel(int32_t size, float64_t g, float64_t c)
: CDotKernel(size)
{
	init();

	gamma=g;
	coef0=c;
}

CSigmoidKernel::CSigmoidKernel(
	CDotFeatures* l, CDotFeatures* r, int32_t size, float64_t g, float64_t c)
: CDotKernel(size)
{
	init();

	gamma=g;
	coef0=c;

	init(l,r);
}

CSigmoidKernel::~CSigmoidKernel()
{
	cleanup();
}

void CSigmoidKernel::cleanup()
{
}

bool CSigmoidKernel::init(CFeatures* l, CFeatures* r)
{
	CDotKernel::init(l, r);
	return init_normalizer();
}

void CSigmoidKernel::init()
{
	gamma=0.0;
	coef0=0.0;

	SG_ADD(&gamma, "gamma", "Gamma.", ParameterProperties::HYPER);
	SG_ADD(&coef0, "coef0", "Coefficient 0.", ParameterProperties::HYPER);
}
