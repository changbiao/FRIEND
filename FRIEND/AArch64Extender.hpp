//
//  AArch64Extender.hpp
//  Flexible Register/Instruction Extender aNd Documentation
//
//  Created by Alexander Hude on 11/11/2016.
//  Copyright © 2017 Alexander Hude. All rights reserved.
//

#pragma once

#include "capstone.h"

#include "ProcExtender.hpp"

class AArch64Extender : public ProcExtender
{
public:
	
	AArch64Extender() {};
	~AArch64Extender() {};
	
	bool	init() override;
	bool	close() override;
	
	bool	output(uint16_t itype, ea_t address, uint32_t size, ProcOutput& procOutput) override;
	
	bool	getSystemRegisterName(ea_t address, char* nameBuffer, uint32_t nameLength) override;
	
private:
	
	bool	isEnabled() override;
	bool	setEnabled(bool enabled) override;
	
	bool	printCapstoneOutput(ea_t address, uint32_t size, ProcOutput& procOutput);
	
private:
	
	csh		m_capstoneHandle = 0;
};
