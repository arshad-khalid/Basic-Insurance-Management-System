# Health Insurance Management System

## Overview
This system, implemented in C, will help manage subscriptions, claims, and account information efficiently.

## Insurance Plans

### Assumed Plans and Benefits

| Plan      | Monthly Premium (RM) | Annual Claim Limit (RM) | Lifetime Claim Limit (RM) |
|-----------|-----------------------|-------------------------|----------------------------|
| Plan120   | 120                   | 120,000                 | 600,000                    |
| Plan150   | 150                   | 150,000                 | 750,000                    |
| Plan200   | 200                   | 200,000                 | 1,000,000                  |

### Assumed Eligibility by Age Group

| Age Group (Years)   | Plan120 | Plan150 | Plan200 |
|---------------------|---------|---------|---------|
| 15 days – 20 years  | ✓       | ✓       | ✓       |
| 21 – 40 years       | ✓       | ✓       |         |
| 41 – 54 years       | ✓       |         |         |

### Assumed Hospitalisation and Surgical Benefits

| Type of Claim                        | Plan120      | Plan150      | Plan200      |
|--------------------------------------|--------------|--------------|--------------|
| Room Charges                         | 120/day      | 150/day      | 200/day      |
| ICU Charges                          | 250/day      | 400/day      | 700/day      |
| Hospital Supplies and Services       | As charged       (subject to approval)     |
| Surgical Fees                        | As charged   | As charged   | As charged   |

## Features Implemented

### 1. Insurance Plan Subscription
- **User Input**: Prompt for age, display eligible plans and benefits.
- **Claim Limit Type**: Choose between Annual and Lifetime.
- **Subscriber Details**: Collect name, contact number, address, health history.
- **Unique ID**: Generate a sequential subscriber ID.
- **Data Storage**: Save subscriber details in a text file.

### 2. Claim Processing
- **Claim Submission**: Allow users to submit claims.
- **Claim Details**: Input for hospitalization duration, costs, etc.
- **Eligibility Check**: Validate claims against subscriber limits.
- **Record Keeping**: Maintain records of claims and balance amounts.

### 3. Accounts Information
- **Total Claims**: Display total amount claimed by Lifetime Claim Limit subscribers.
- **Exhausted Claims**: Count Annual Claim Limit subscribers who have exhausted their claims.

### 4. Searching Functionalities
- **Search Options**:
  - By Subscriber ID or name.
  - By Plan, claim limit type, and age.

## Requirements
- Conducted research and documented assumptions.
- Used symbolic constants and validated inputs.
- Stored data in minimal text files.
- Utilized C programming constructs: control structures, functions, arrays, pointers, structures, unions.
- Implemented modular programming with a menu-driven interface.
