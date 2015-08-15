/*************************************************************************
 *                                                                       *
 * Vega FEM Simulation Library Version 2.1                               *
 *                                                                       *
 * "forceModel" library , Copyright (C) 2007 CMU, 2009 MIT, 2014 USC     *
 * All rights reserved.                                                  *
 *                                                                       *
 * Code author: Jernej Barbic                                            *
 * http://www.jernejbarbic.com/code                                      *
 *                                                                       *
 * Research: Jernej Barbic, Fun Shing Sin, Daniel Schroeder,             *
 *           Doug L. James, Jovan Popovic                                *
 *                                                                       *
 * Funding: National Science Foundation, Link Foundation,                *
 *          Singapore-MIT GAMBIT Game Lab,                               *
 *          Zumberge Research and Innovation Fund at USC                 *
 *                                                                       *
 * This library is free software; you can redistribute it and/or         *
 * modify it under the terms of the BSD-style license that is            *
 * included with this library in the file LICENSE.txt                    *
 *                                                                       *
 * This library is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the file     *
 * LICENSE.TXT for more details.                                         *
 *                                                                       *
 *************************************************************************/

#include "isotropicHyperelasticFEMForceModel.h"

IsotropicHyperelasticFEMForceModel::IsotropicHyperelasticFEMForceModel(IsotropicHyperelasticFEM * isotropicHyperelasticFEM_): isotropicHyperelasticFEM(isotropicHyperelasticFEM_)
{
  r = 3 * isotropicHyperelasticFEM->GetTetMesh()->getNumVertices();
}

IsotropicHyperelasticFEMForceModel::~IsotropicHyperelasticFEMForceModel() {}

void IsotropicHyperelasticFEMForceModel::GetInternalForce(double * u, double * internalForces)
{
  isotropicHyperelasticFEM->ComputeForces(u, internalForces);
}

shared_ptr<SparseMatrix> IsotropicHyperelasticFEMForceModel::ConstructTangentStiffnessMatrix()
{
  auto topology = isotropicHyperelasticFEM->GetStiffnessMatrixTopology();
    return std::make_shared<SparseMatrix>(topology);
}

void IsotropicHyperelasticFEMForceModel::GetTangentStiffnessMatrix(double * u, shared_ptr<SparseMatrix> tangentStiffnessMatrix)
{
  isotropicHyperelasticFEM->GetTangentStiffnessMatrix(u, tangentStiffnessMatrix.get());
} 

void IsotropicHyperelasticFEMForceModel::GetForceAndMatrix(double * u, double * internalForces, shared_ptr<SparseMatrix> tangentStiffnessMatrix)
{
  isotropicHyperelasticFEM->GetForceAndTangentStiffnessMatrix(u, internalForces, tangentStiffnessMatrix.get());
}

